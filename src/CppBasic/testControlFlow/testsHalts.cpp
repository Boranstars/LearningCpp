#include <cstdlib>
#include <iostream>
#include "testsHalts.h"

void cleanUp()
{   
    // 模拟清理资源
    std::cout << "cleanUp()\n";
}
int main(int argc, char const *argv[])
{
    // testExit();
    std::cout << "1\n";
    std::abort(); // 程序异常退出

    return 0;
}

void testExit()
{

std:
    std::cout << "zaaaa" << std::endl;
    // cleanUp();
    std::atexit(cleanUp); // 注册清理函数
    std::exit(0);         // 程序正常退出

    std::cout << "This line will not be executed\n";
}

