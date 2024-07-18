#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <functional>
int main(int argc, char const *argv[])
{


    // lambda函数 [](){}; 用于定义一个匿名函数
    auto add = [](int a, int b) -> int
    {
        return a + b;
    };
    std::cout << add(1, 2) << std::endl;


    // lambda函数可以捕获外部变量
    int x = 10;
    auto addX = [x](int a) -> int
    {
        return a + x;
    };
    std::cout << addX(1) << std::endl;


    // lambda函数默认是const的, 如果需要修改外部变量, 需要使用mutable
    auto addXMutable = [x](int a) mutable -> int
    {
        x += a; // x是一个拷贝, 不会修改外部变量
        return x;
    };
    std::cout << addXMutable(4) << std::endl;
    std::cout << x << std::endl;


    // lambda函数可以修改外部变量, 但是需要使用引用
    auto addXRef = [&x](int a) -> int
    {
        x += a; // x是一个引用, 会修改外部变量
        return x;
    };
    std::cout << addXRef(3) << std::endl;
    std::cout << x << std::endl;

    int y = 20, z = 30;
    // lambda函数可以捕获所有外部变量
    // [=]表示捕获所有外部变量, [&]表示捕获所有外部变量的引用
    auto addAll = [=](int a) -> int
    {
        return a + x + y + z;
    };
    auto addAllRef = [&](int a) -> int
    {
        x += a;
        y += a;
        z += a;
        return x + y + z;
    };
    std::cout << addAll(1) << std::endl;
    std::cout << addAllRef(1) << std::endl;

    // lambda函数可以指定返回值类型, 如果不指定, 则根据返回值自动推导
    auto addAllAuto = [=](int a)
    {
        return a + x + y + z;
    };

    //可以在闭包中定义局部变量，仅在闭包中有效
    auto isMin = [min {3}](int x) -> int { return min > x; };
    // min = 4;


    int i = 0;
    // 拷贝lambda函数时
    auto counter = [i]() mutable -> int {
        std::cout << "i = " << ++i << std::endl;
    };
    // 拷贝的lambda函数是独立的，执行的是原lambda函数的拷贝
    auto antherCounter = counter;
    counter();
    void myInvoke(const std::function<void()>& func);
    myInvoke(counter);
    myInvoke(counter);
    myInvoke(std::ref(counter));    // 使用std::ref可以传递引用
    myInvoke(std::ref(counter));
    return 0;
}

void myInvoke(const std::function<void()>& func)
{
    func();
}
