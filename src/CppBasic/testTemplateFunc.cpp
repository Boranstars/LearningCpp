#include <iostream>
#if __cplusplus >= 202002L
#define CPP20
#elif __cplusplus >= 201703L
#define CPP17
#endif

// 模板函数
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// 模板函数 ，使用auto关键字
template <typename T>
auto add2(T a, T b) -> decltype(a + b)
{
    return a + b;
}

#ifdef CPP20
// 模板函数 ，使用auto关键字, C++20中可以直接使用auto
auto add3(auto a, auto b)
{
    return a + b;
}
#endif //

#ifdef CPP17
// 上面等价于
template <typename T, typename U>
auto add3(T a, U b)
{
    return a + b;
}

#endif // CPP17

int main(int argc, char const *argv[])
{
    int a{1}, b{2};
    double c{3.6};
    std::cout << add(a, b) << "\ta + b \n";
    std::cout << add2(a, b) << "\ta + b \n";
    std::cout << add2(c, c) << "\tc + c \n";
    std::cout << add3(a, c) << "\ta + c \n";
    return 0;
}
