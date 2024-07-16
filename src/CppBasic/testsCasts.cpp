#include <iostream>

int main(int argc, char const *argv[])
{
    int a { 10 };
    int b { 4 };

    double c { static_cast<double>(a) / b }; // C++ 风格的类型转换
    double d { (double)a / b }; // C 风格的类型转换
    double e { double(a) / b }; // C 风格的类型转换,类似于函数调用,Python 风格
    double f { a / b }; // 整数相除,结果为整数,这会导致精度丢失

    return 0;
}
