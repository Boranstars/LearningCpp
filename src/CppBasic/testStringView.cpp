#include <iostream>
#include <string_view>
#include <string>




void printStringView(std::string_view strView);
/**
 * C++17 引入了 std::string_view 类，它是一个轻量级的字符串视图。
 * 
 * 字符串视图是一个只读的字符串，它不拥有字符串的内存，而是指向现有字符串的内存。
 * 字符串视图的目的是提供一种轻量级的字符串处理方式，避免创建临时字符串。
 * 
 * 在这个程序中，我们创建了一个字符串 "Hello, World!"，然后创建了一个字符串视图 strView。
 * 
 * @param argc 命令行参数的数量。
 * @param argv 命令行参数的数组。
 * @return int 程序的退出状态。
 */
int main(int argc, char const *argv[])
{   
    std::string str {"Hello, World!"}; // 创建一个字符串
    std::string_view strView {str}; // 创建一个字符串视图

    constexpr std::string_view strView2 {"Hello, conststr!"}; // 创建一个常量表达式字符串视图
    printStringView(strView); // 打印字符串视图
    std::cout << strView2 << std::endl; // s 会在编译时被替换为 "Hello, world!"


    // 字面量后缀
    using namespace std::literals;
    std::cout << "foo"; // 普通字符串
    std::cout << "bar"s; // 使用 std::string
    std::cout << "baz"sv; // 使用 std::string_view
    return 0;
}
/**
 * 打印字符串视图。
 * 当需要使用只读字符串时，使用 std:: string_view 
 * 而不是 std:: string ，尤其是函数形参。
 * @param strView 字符串视图。
 */
void printStringView(std::string_view strView)
{
    std::cout << strView << std::endl;
}
/**
 * 打印字符串。
 * @param str 字符串。
 */
void printString(std::string str)
{
    std::cout << str << std::endl;
}
void strv2str()
{
    std::string_view strView {"Hello, World!"}; // 创建一个字符串视图
    std::string str {strView}; // 将字符串视图转换为字符串
    // printStringView(str); // 错误：无法将字符串转换为字符串视图
    printString(str); // 正确：可以将字符串视图转换为字符串
}