#include <iostream>
#include <vector>
#include <chrono>

#include "ThreadPool.h"

int main()
{
    // create thread pool with 4 worker threads �������� 4 �������̵߳��̳߳�
    ThreadPool pool(4);
    std::vector< std::future<int> > results;

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "�߳�" << i << "step1" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "�߳�" << i << "step2" << std::endl;
                return i*i;
            })
        );
    }

    for(auto && result: results)
        std::cout << "ִ�н����" << result.get() << ' ' << std::endl;
    std::cout << std::endl;
    
    return 0;
}
