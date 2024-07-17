#include <iostream>
#include <random>
#include <ctime>
#include "testDynamicMemory.h"
int main(int argc, char const *argv[])
{
    // testPtr();
    std::srand(std::time(nullptr));
    int length { std::rand() % 100 };
    int *arr = new int[length];
    arr[0] = 114514;
    delete[] arr;
    std::cout << "finish" << std::endl;
    return 0;
}

void testPtr()
{
    int a = 3;
    int *ptr = &a;
    int *ptr1 = new int; //
    *ptr1 = 10;
    int *ptr2{new int(20)};
    delete ptr1;
    ptr1 = nullptr;
}
