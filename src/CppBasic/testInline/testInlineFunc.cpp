#include <iostream>

/**
 * @brief 内联命名空间
 * 内联命名空间是 C++11 新增的特性，它允许将命名空间的定义和声明分开。
 * 内联命名空间的定义可以出现在多个翻译单元中，而不会引起重定义错误。
 * 定义在内联命名空间中的内容都属于其父命名空间。
 */
inline namespace v1 // 声明内联命名空间 v1
{
    void doSomething()
    {
        std::cout << "v1\n";
    }
}

namespace v2 // 声明命名空间 v2
{
    void doSomething()
    {
        std::cout << "v2\n";
    }
}

int main()
{
    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v1)

    return 0;
}
