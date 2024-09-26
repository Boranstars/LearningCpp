#include <iostream>

class Base
{
private:
    int id {0};
public:
    Base(int id) :id{ id } {}
    int getID() const { return id; }
    ~Base() {};
};

class testInheritance : public Base
{
private:
    double my_cost;
public:
    testInheritance(int id, double cost): 
        Base { id }, // 调用基类构造函数
        my_cost { cost }
    {

    }
    double getCost() const 
    {
        return this->my_cost;
    }
    ~testInheritance() {}
};

int main(int argc, char const *argv[])
{
    testInheritance ti {5, 1.6};
    std::cout << ti.getID() << std::endl;
    std::cout << ti.getCost() << std::endl;
    return 0;
}
