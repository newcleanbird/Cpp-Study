#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>    // 可变参数模板 F:函数返回类型 Args:函数参数
    auto enqueue(F&& f, Args&&... args) // 右值引用
        -> std::future<typename std::result_of<F(Args...)>::type>;  // 函数返回类型后置
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them    跟踪线程
    std::vector< std::thread > workers;
    // the task queue   任务队列
    std::queue< std::function<void()> > tasks;
    
    // synchronization  同步
    std::mutex queue_mutex; // 互斥锁
    std::condition_variable condition;  // 条件变量,允许线程等待某个条件成立，并在条件满足时被唤醒
    bool stop;
};
 
// the constructor just launches some amount of workers 构造函数：启动任意数量的线程
inline ThreadPool::ThreadPool(size_t threads) : stop(false)
{
    for(size_t i = 0;i < threads; ++i)
        workers.emplace_back(
            [this]  // lambda表达式捕获列表， [this]表示捕获当前对象的指针
            {
                for(;;)
                {
                    std::function<void()> task; // 用于存储待执行的任务

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);   // 对任务队列进行加锁，以确保线程安全地访问任务队列。
                        this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });   // 使线程等待，直到条件满足或被通知
                        if(this->stop && this->tasks.empty()) // 线程等待或任务队列为空，则返回
                            return;
                        task = std::move(this->tasks.front());  // 从队列中取出任务
                        this->tasks.pop();
                    }

                    task();
                }
            }
        );
}

// add new work item to the pool    向池中添加新的工作项
// 接受一个可调用对象（函数或lambda表达式）和一系列参数，将任务添加到线程池中并返回一个std::future对象，用于获取任务的执行结果。
template<class F, class... Args>    // 使用模板参数F和Args...来表示可调用对象的类型和参数类型。
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;  // 定义一个名为return_type的类型别名，表示可调用对象的返回类型。

    auto task = std::make_shared< std::packaged_task<return_type()> >(  // 创建一个std::packaged_task对象，将传入的可调用对象和参数绑定到这个任务上。
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
    std::future<return_type> res = task->get_future();  // 获取任务的std::future对象，用于后续获取任务的执行结果。
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // 使用std::unique_lock对队列互斥量进行加锁，确保在添加任务时不会发生数据竞争。

        // don't allow enqueueing after stopping the pool 检查线程池是否已经停止，如果已经停止则抛出异常。
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); });  // 将任务添加到任务队列中。
    }
    condition.notify_one(); // 通知等待条件变量的一个线程，表示有新的任务可以执行。
    return res; // 返回任务的std::future对象。
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // 通过创建一个std::unique_lock对象来锁定互斥量queue_mutex，以确保在修改共享变量stop时不会发生数据竞争。
        stop = true;    // 将stop设置为true，表示线程池应该停止工作。
    }
    condition.notify_all(); // 调用condition.notify_all()来唤醒所有等待在条件变量condition上的线程，通知它们线程池即将关闭。
    for(std::thread &worker: workers)   // 最后，使用循环遍历线程池中的每个工作线程，并调用worker.join()来等待每个工作线程完成其任务并退出。这样可以确保所有工作线程都已经完成其任务后再销毁线程池对象。
        worker.join();
}

#endif
