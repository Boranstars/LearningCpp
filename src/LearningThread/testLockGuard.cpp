#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


void getSum(int& num, std::mutex& mtx)
{   
    // lock_guard是一个RAII类，构造时会锁住互斥量，析构时会释放互斥量
    // lock_guard的作用是保证互斥量在任何情况下都会被释放
    // lock_guard的构造函数会调用mtx.lock()，析构函数会调用mtx.unlock()
    // lock_guard不可拷贝，不可移动
    std::lock_guard<std::mutex> lock {mtx};
    for (size_t i = 0; i < 1000000; i++)
    {
        ++num;
    }
    std::cout << std::this_thread::get_id() << std::endl;
    // mtx.unlock(); // 不需要手动释放互斥量
    
}

int main(int argc, char const *argv[])
{
    std::mutex myMutex;
     
    std::vector<std::thread> threads;
    int num = 0;
    for (size_t i = 0; i < 10; i++)
    {   
        // 使用emplace_back()函数构造线程,避免拷贝传参
        // std::ref()将num和myMutex传递给线程,使用std::ref()是因为std::thread的构造函数是拷贝传参的
        threads.emplace_back(getSum,std::ref(num),std::ref(myMutex));
    }
    
    // 线程等待，这里需要使用引用
    for(auto& thread : threads)
    {
        thread.join();
    }

    std::cout << num << std::endl;
    return 0;
}
