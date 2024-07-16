#include <iostream>
#include <string>

namespace foo
{
    int plus(int a, int b)
    {
        return a + b;
    }

} // namespace foo

namespace bar
{
    int plus(int a, int b)
    {
        return a + b;
    }
} // namespace bar

int plus(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    std::cout << foo::plus(1, 2) << std::endl; // foo 命名空间
    std::cout << bar::plus(1, 2) << std::endl; // bar 命名空间
    std::cout << ::plus(1, 2) << std::endl; // 全局命名空间
    return 0;
}