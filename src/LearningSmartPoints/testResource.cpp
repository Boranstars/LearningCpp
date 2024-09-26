#include "Resource.hpp"

int main(int argc, char const *argv[])
{
    Resource rs1("Rs1");
    Resource rs;
    std::cout << rs1 << std::endl;
    std::cout << rs << std::endl;
    return 0;
}
