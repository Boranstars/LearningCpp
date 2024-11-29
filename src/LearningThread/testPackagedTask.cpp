#include <future>
#include <iostream>
#include <ostream>
#include <thread>

int add(int a, int b) { return a + b; }

int main(int argc, const char **argv) {
    // packaged_task 用于将函数包装成一个 future 对象
    std::packaged_task<int(int, int)> task1(
        [](int a, int b) -> int { return a + b; }); // 使用 lambda 初始化, 也可以使用函数指针
    auto fut1 = task1.get_future(); // 获取 future 对象

    std::packaged_task<decltype(add)> task2(add); // 使用函数指针初始化,这里的 decltype(add) 会返回 add 函数的类型
    auto fut2 = task2.get_future();
    std::cout << "task1 is " << (task1.valid() ? "valid" : "not valid") << std::endl; // packaged_task 是否有效
    std::cout << "task2 is " << (task2.valid() ? "valid" : "not valid") << std::endl;
    auto t1 = std::thread(std::move(task1), 3, 6);
    auto t2 = std::thread(std::move(task2), 4, 8);
    std::cout << fut1.get() << std::endl;
    std::cout << fut2.get() << std::endl;
    std::cout << "task1 is " << (task1.valid() ? "valid" : "not valid") << std::endl; // packaged_task 是否有效
    std::cout << "task2 is " << (task2.valid() ? "valid" : "not valid") << std::endl;

    t1.join();
    t2.join();
    return 0;
}