#include <iostream>
#include <thread>
#include <unistd.h>

void printHello(const std::string &msg) { std::cout << msg << std::endl; }

void getInput(const bool& isTerminated) {
    while (!isTerminated) {
        std::string buf;
        std::cout << "Enter A number" << std::endl;
        std::cin >> buf;
        std::cout << "You entered: " << buf << std::endl;
    }
}

void printMsg(bool& isTerminated) {
    for (size_t i = 0; i < (size_t)10; i++) {
        sleep(1);
        std::cout << "Counter: " << i << std::endl;
    }
    isTerminated = true;
}
int main(int argc, char const *argv[]) {
    // 创建一个线程
    std::thread thread1(printHello, "Hello Thread");

    // 判断线程是否可连接
    if (thread1.joinable()) {
        // 等待线程结束
        thread1.join();
    }
    bool flag = false;
    std::thread inputThread(getInput,std::ref(flag));
    std::thread printThread(printMsg,std::ref(flag));
    inputThread.join();
    printThread.join();
    // 主线程
    std::cout << "Main Thread" << std::endl;

    return 0;
}
