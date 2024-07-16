#if !defined(CONSTANTS_H)
#define CONSTANTS_H
// 全局常量应该在头文件中声明
//  但是，如果在多个源文件中包含此头文件，则每个源文件都将包含常量的副本。
//  为了避免这种情况，我们可以使用内联变量。
//  内联变量是C++17的新功能，它允许我们在头文件中声明常量，而不会引起重定义错误。
//  但是，如果我们在多个源文件中包含此头文件，则只有一个常量的副本。
//  为了使用内联变量，我们需要在声明和定义中使用关键字inline。
//  例如，我们可以在头文件中声明常量，然后在源文件中定义它们。
namespace constants
{
    inline constexpr double pi{3.14159};
    inline constexpr double avogadro{6.0221413e23};
    inline constexpr double my_gravity{9.2};
    inline constexpr double moon_gravity{1.6};
    inline constexpr double sun_gravity{274};
    // 一些常量

    // 内联变量有两个主要的限制，需要我们遵循：

    // 内联变量的所有定义必须是完全一致的（否则会产生未定义行为）。
    // 内联变量的定义（而非声明）必须出现在任何使用它们的文件中。
} // namespace constants

#endif // CONSTANTS_H
