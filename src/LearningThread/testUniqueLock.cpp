#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
void testUniqueLock(std::mutex& mtx)
{   
    // unique_lock是一个RAII类，构造时会锁住互斥量，析构时会释放互斥量
    std::unique_lock<std::mutex> ulk {mtx}; // 这样构造会自动上锁
    std::cout << "testUniqueLock" << std::endl;
    
}

void testDeferredLock(std::mutex& mtx)
{
    
    std::unique_lock<std::mutex> ulk {mtx, std::defer_lock}; // 这样构造不会自动上锁
    ulk.lock(); // 手动上锁
    std::cout << "testDeferredLock" << std::endl;
    // 这里和lock_guard的表现一样，不需要手动解锁。
}

void testTryToLock(std::mutex& mtx)
{   
    // mtx.lock();
    std::unique_lock<std::mutex> ulk {mtx, std::try_to_lock}; // 尝试上锁

    // 判断是否上锁成功
    if(ulk.owns_lock())
    {   
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "testTryToLock" << std::endl;
    }
    else
    {
        std::cout << "testTryToLock failed" << std::endl;
    }
}

void testAdoptLock(std::mutex& mtx)
{
    mtx.lock(); // 使用adopt_lock构造时，一定被上锁了，才能接管锁。
    std::unique_lock<std::mutex> ulk {mtx, std::adopt_lock}; // 接管锁
    if (mtx.try_lock())
    {
        std::cout << "locked!" << std::endl;
    }
    
    if (ulk.owns_lock())
    {
        std::cout << "adopt successs" << std::endl;
    }
    
    
}

int main(int argc, char const *argv[])
{
    std::mutex mtx;
    std::thread t1(testTryToLock,std::ref(mtx));
    std::thread t2(testAdoptLock,std::ref(mtx));
    t1.join();
    t2.join();
    return 0;
}

