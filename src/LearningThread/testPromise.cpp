#include <chrono>
#include <functional>
#include <thread>
#include <iostream>
#include <future>
// using namespace std;
void foo(std::promise<int>& prom)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(42);

}


int main(int argc, const char** argv) {
    std::promise<int> prom; // promise 会在某个线程中设置值
    std::future<int> f = prom.get_future(); // future 会在另一个线程中获取值

    auto thread = std::thread(foo, std::ref(prom)); // 传递 promise 引用

    std::cout << f.get() << std::endl; // 42, 但是这里会等待 foo 设置值,是阻塞的
    thread.join();
    return 0;
}   