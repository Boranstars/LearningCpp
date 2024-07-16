#include <iostream>
#if __cplusplus >= 202002L
#include <type_traits>
#define CPP20
#elif __cplusplus >= 201703L
#define CPP17
#endif

#if defined(CPP17)
/**
 * @brief constexpr 函数
 * constexpr 函数是在编译时求值的函数。它们是用于计算常量表达式的函数。
 * constexpr 函数可以返回常量或字面值类型的值。
 * constexpr 函数具有隐含内联属性,
 * 但是，如果函数的结果不是常量表达式，则它将被视为内联函数。
 * 使函数具有constexpr返回值类型即可以在编译时求值也可以在运行时求值，
 * 因此这样的函数可以满足两种场景。
 * 如果不是这样的话，你就必须定义两个不同的函数（
 * constexpr 版本和非 constexpr 版本），但是由于返回值类型不能用来区别函数重载，
 * 所以你就不得不为它起一个不同的名字。
 * 在 C++11 中，constexpr 函数只能包含一条 return 语句。
 * 从 C++14 开始，constexpr 函数可以包含多条 return 语句。
 * 在 C++20 中，constexpr 函数可以包含局部变量、循环和分支语句。
 *
 */
constexpr int greater(int a, int b)
{
    return a > b ? a : b;
}
#endif // CPP17
#if defined(CPP20)
/**
 * @brief consteval 函数
 * consteval 函数是在编译时求值的函数。它们是用于计算常量表达式的函数。
 * consteval 函数必须在编译时求值，否则编译器会报错。
 * 这与constexpr不同，constexpr函数可以在编译时求值也可以在运行时求值。
 */
consteval int greater(int a, int b)
{
    return a > b ? a : b;
}

#endif // CPP20

int main(int argc, char const *argv[])
{

#if defined(CPP17)
    constexpr int a = 10;
    constexpr int b = 20;
    constexpr int c = greater(a, b); // 编译时求值

    int d = 30;
    int e = 40;

    int f = greater(d, e); // 运行时求值

#endif // CPP17

#if defined(CPP20)
    constexpr int a = 10;
    constexpr int b = 20;
    constexpr int c = greater(a, b); // 编译时求值

    int d = 30;
    // int e = greater(d, 40); // 这里会报错，因为在编译时求值时，参数必须是常量表达式
#endif // CPP20

    return 0;
}
