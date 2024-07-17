#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*));

 

/**
 * @brief 
 * 左值引用，会绑定到左值上，不能绑定到右值上
 * 会修改原来的值
 */
void addOneL(int &a)
{
    a++;
}

/**
 * @brief
 * 值传递，不会修改原来的值
 */
void addOne(int a)
{
    a++;
}

/**
 * @brief
 * const左值引用，可以绑定到右值上
 */
void printValue(const int &a)
{
    std::cout << a << std::endl;
}

/**
 * @brief
 * 对于拷贝开销大的对象，如果不需要修改，
 * 可以使用const左值引用
 */
void printString(const std::string &str)
{
    std::cout << str << std::endl;
}

int main(int argc, char const *argv[])
{
    int a = 1;
    addOne(a);
    std::cout << a << std::endl;
    addOneL(a);
    std::cout << a << std::endl;

    std::string str = "hello";
    printString(str);
    return 0;
}
