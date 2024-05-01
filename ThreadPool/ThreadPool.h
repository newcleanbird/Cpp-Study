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
    template<class F, class... Args>    // �ɱ����ģ�� F:������������ Args:��������
    auto enqueue(F&& f, Args&&... args) // ��ֵ����
        -> std::future<typename std::result_of<F(Args...)>::type>;  // �����������ͺ���
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them    �����߳�
    std::vector< std::thread > workers;
    // the task queue   �������
    std::queue< std::function<void()> > tasks;
    
    // synchronization  ͬ��
    std::mutex queue_mutex; // ������
    std::condition_variable condition;  // ��������,�����̵߳ȴ�ĳ������������������������ʱ������
    bool stop;
};
 
// the constructor just launches some amount of workers ���캯�������������������߳�
inline ThreadPool::ThreadPool(size_t threads) : stop(false)
{
    for(size_t i = 0;i < threads; ++i)
        workers.emplace_back(
            [this]  // lambda���ʽ�����б� [this]��ʾ����ǰ�����ָ��
            {
                for(;;)
                {
                    std::function<void()> task; // ���ڴ洢��ִ�е�����

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);   // ��������н��м�������ȷ���̰߳�ȫ�ط���������С�
                        this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });   // ʹ�̵߳ȴ���ֱ�����������֪ͨ
                        if(this->stop && this->tasks.empty()) // �̵߳ȴ����������Ϊ�գ��򷵻�
                            return;
                        task = std::move(this->tasks.front());  // �Ӷ�����ȡ������
                        this->tasks.pop();
                    }

                    task();
                }
            }
        );
}

// add new work item to the pool    ���������µĹ�����
// ����һ���ɵ��ö��󣨺�����lambda���ʽ����һϵ�в�������������ӵ��̳߳��в�����һ��std::future�������ڻ�ȡ�����ִ�н����
template<class F, class... Args>    // ʹ��ģ�����F��Args...����ʾ�ɵ��ö�������ͺͲ������͡�
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;  // ����һ����Ϊreturn_type�����ͱ�������ʾ�ɵ��ö���ķ������͡�

    auto task = std::make_shared< std::packaged_task<return_type()> >(  // ����һ��std::packaged_task���󣬽�����Ŀɵ��ö���Ͳ����󶨵���������ϡ�
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
    std::future<return_type> res = task->get_future();  // ��ȡ�����std::future�������ں�����ȡ�����ִ�н����
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // ʹ��std::unique_lock�Զ��л��������м�����ȷ�����������ʱ���ᷢ�����ݾ�����

        // don't allow enqueueing after stopping the pool ����̳߳��Ƿ��Ѿ�ֹͣ������Ѿ�ֹͣ���׳��쳣��
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); });  // ��������ӵ���������С�
    }
    condition.notify_one(); // ֪ͨ�ȴ�����������һ���̣߳���ʾ���µ��������ִ�С�
    return res; // ���������std::future����
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // ͨ������һ��std::unique_lock����������������queue_mutex����ȷ�����޸Ĺ������stopʱ���ᷢ�����ݾ�����
        stop = true;    // ��stop����Ϊtrue����ʾ�̳߳�Ӧ��ֹͣ������
    }
    condition.notify_all(); // ����condition.notify_all()���������еȴ�����������condition�ϵ��̣߳�֪ͨ�����̳߳ؼ����رա�
    for(std::thread &worker: workers)   // ���ʹ��ѭ�������̳߳��е�ÿ�������̣߳�������worker.join()���ȴ�ÿ�������߳�����������˳�����������ȷ�����й����̶߳��Ѿ������������������̳߳ض���
        worker.join();
}

#endif
