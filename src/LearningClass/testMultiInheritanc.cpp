#include <iostream>
class BaseA
{
private:
    int foo;
    

public:
    BaseA(/* args */) {}
    BaseA(int foo) : foo(foo) {};
    ~BaseA() {}

public:
    int getFoo() 
    {
        return this->foo;
    }
};

class BaseB
{
private:
    int foo;
    

public:
    BaseB(/* args */) {}
    BaseB(int foo) : foo(foo) {};
    ~BaseB() {}

public:
    int getFoo() 
    {
        return this->foo * 2;
    }
};
class testMultiInheritanc : public BaseA, public BaseB
{
private:
    
public:
    testMultiInheritanc(/* args */) {}
    testMultiInheritanc(int foo): BaseA(foo),BaseB(foo) {};
    ~testMultiInheritanc() {}
};


int main(int argc, char const *argv[])
{   
    testMultiInheritanc tMI1(33);
    // int bar = tMI1.getFoo(); // 这样会报错，因为编译器不知道调用哪个getFoo
    int barA = tMI1.BaseA::getFoo();
    int barB = tMI1.BaseB::getFoo();
    std::cout << barA << "\n" << barB << std::endl;
    return 0;
}

