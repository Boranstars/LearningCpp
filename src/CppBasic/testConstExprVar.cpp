#include <iostream>

int getNumber();
/**
 * 编译时常量和常量表达式的区别：
 * 
 * 编译时常量是使用 const 关键字声明的常量。它们在运行时是只读的，不能在初始化后修改。
 * 常量表达式是使用 constexpr 关键字声明的常量。它们在编译时被求值，并且在运行时也是只读的，不能修改。
 * 
 * 在这个程序中，我们有三个变量：'i'、'j' 和 'k'。
 * - 'i' 使用 const 关键字声明为编译时常量。它在初始化后不能被修改。
 * - 'j' 使用 constexpr 关键字声明为常量表达式。它在编译时被求值，并且在初始化后不能被修改。
 * - 'k' 是一个普通变量，可以被修改。
 * 
 * 如果取消注释尝试修改 'i' 或 'j' 的行，将会导致编译错误，因为它们是只读的。
 * 修改 'k' 是允许的，不会导致任何错误。
 * 
 * @param argc 命令行参数的数量。
 * @param argv 命令行参数的数组。
 * @return int 程序的退出状态。
 */
int main(int argc, char const *argv[])
{
    const int i = 10; // const 说明是一个编译时常量
    constexpr int j = 20; // constexpr 说明是一个常量表达式
    constexpr int sum {i + j}; // sum 是一个常量表达式
    constexpr int product {i * j}; // product 是一个常量表达式
    int k = 30; // 普通变量

    // i = 20; // 错误：无法修改只读变量 'i'
    // j = 30; // 错误：无法修改只读变量 'j'
    k = 40; // 正确

    const int x {10}; // x 是一个编译时常量
    const int y {getNumber()}; // y 是一个运行时常量
    std::cout << x + y; // x + y 是一个运行时常量

    // constexpr int z {getNumber()}; // 错误：getNumber() 不是一个常量表达式
    return 0;
}

int getNumber()
{
    std::cout << "Enter a number: "; 
    int y{};
    std::cin >> y;

    return y;
}