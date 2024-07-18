#include <iostream>

/**
 * @brief
 * 命令行参数测试
 * 对于命令行参数，argc表示参数个数，argv是一个指针数组，每个元素是一个指向参数的指针
 */
int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    return 0;
}