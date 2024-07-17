#include <iostream>
#include <string>
#include <string_view>

int main(int argc, char const *argv[])
{   
    using namespace std::literals;
    auto a = 1; // int
    auto b = 1.0;   // double
    auto c = "hello"; // const char*

    const int x { 5 };
    auto y = x; // const 会被忽略
    const auto z = x; // const 会被保留    

    auto s1 { "fpp"s}; // std::string
    auto s2 { "fpp"sv}; // std::string_view

    return 0;
}

