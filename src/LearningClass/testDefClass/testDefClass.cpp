#include "testDefClass.hpp"
#include <iostream>
#include <string>

int testDefClass::getDef1() const
{
    return def1;
}
std::string_view testDefClass::getDef2() const
{
    return def2;
}
void testDefClass::setDef2(std::string_view def2)
{
    this->def2 = def2;
}

int main(int argc, char const *argv[])
{
    testDefClass test(1, "test");
    const testDefClass test2(2, "test2");
    test.setDef2("test1");
    std::cout << test.getDef1() << "\n" << test.getDef2() << std::endl;
    std::cout << test2.getDef1() << "\n" << test2.getDef2() << std::endl;
    return 0;
}
