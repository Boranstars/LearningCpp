#include <iostream>
#include <mutex>
#include <thread>

void conuter(int &num) {
    for (int i = 0; i < 1000000; i++) {
        // 这会导致数据竞争，num的值会被多个线程同时修改
        num++;
    }
}

void counterMutex(int &num, std::mutex &mtx) {
    mtx.lock();
    for (int i = 0; i < 1000000; i++) {
        // 使用互斥锁保护共享资源
        num++;
    }

    mtx.unlock();
}

int main(int argc, char const *argv[]) {
    int num = 0;
    std::thread t1(conuter, std::ref(num));
    std::thread t2(conuter, std::ref(num));
    t1.join();
    t2.join();
    std::cout << num << std::endl;

    int num2 = 0;
    std::mutex mtx;
    std::thread t3(counterMutex, std::ref(num2), std::ref(mtx));
    std::thread t4(counterMutex, std::ref(num2), std::ref(mtx));
    t3.join();
    t4.join();
    std::cout << num2 << std::endl;

    return 0;
}
