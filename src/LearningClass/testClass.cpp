#include <iostream>
#include <vector>
#include <string>


class subClass
{
private:
    std::string c = "subClass Counstucted";
    std::string d = "subClass destoryed";

public:
    subClass();
    ~subClass();
};

subClass::subClass()
{
    std::cout << this->c << std::endl;
}

subClass::~subClass()
{   
    std::cout << this->d << std::endl;
}


class testClass
{
private:
    int a;
    subClass sc;
    std::string b = "testClass Constructed";
    std::string c = "testClass Destoryed";
public:
    testClass();
    ~testClass();
};

testClass::testClass()
{
    std::cout << this->b << std::endl;
}

testClass::~testClass()
{
    std::cout << this->c << std::endl;
}

int main(int argc, char const *argv[])
{
    
    testClass c1;
    return 0;
}


