#include <iostream>


/**
 * @brief
 * 枚举类型
 * 默认情况下，枚举类型的第一个元素的值为0，后续元素的值依次递增
 */
enum Color
{
    RED, // RED = 0
    GREEN, // GREEN = 1
    BLUE // BLUE = 2
};
// 这样会有问题，因为枚举类型的命名空间是全局的
// enum Color2
// {
//     RED, // RED = 0
//     GREEN, // GREEN = 1
//     BLUE // BLUE = 2
// };

/**
 * @brief
 * 使用枚举类
 * 枚举类的命名空间是独立的
 */
enum class ColorClass 
{
    RED, // RED = 0
    GREEN, // GREEN = 1
    BLUE // BLUE = 2
};



int main(int argc, char const *argv[])
{   
    Color color = RED;
    ColorClass colorClass = ColorClass::RED;
    #if _cplusplus>=202002L
    using enum ColorClass;
    ColorClass colorClass2 = RED;
    #endif
}
