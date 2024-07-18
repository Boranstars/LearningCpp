#include <iostream>
#include <string>
class Employee
{
private:
    int id;
    std::string name;
public:

    /**
     * @brief 
     * 定义在类内部的构造函数是隐式的inline函数
     */
    Employee(int id = 0, std::string_view name = "None") : id( id ), name( name )
    {
        std::cout << "Employee " << this->name << "\nID" << this->id << std::endl;
    };
    /**
     * @brief 委托构造函数
     * 可以使用委托构造函数来避免重复代码
     * 
     */
    // Employee(int id) : Employee(id, static_cast<std::string_view>("")) {};
    Employee(std::string_view name) : Employee{0, name} {};


    /**
     * @brief
     * 非构造函数的成员函数定义在类内部是隐式的inline函数
     */
    void sayHello() {
        std::cout << "Hello, I'm " << this->name << std::endl;
    }

    void sayID();

    /**
     * @brief
     * 析构函数
     * 析构函数没有参数，没有返回值
     * 会在对象生命周期结束时自动调用
     */
    ~Employee() {
        std::cout << "Employee " << this->name << " is destroyed" << std::endl;
    };

};


/**
 * @brief 
 * 定义在类外部的成员函数需要使用作用域解析符
 * 并且不是inline函数
 */
void Employee::sayID()
{
    std::cout << "ID: " << this->id << std::endl;
}


int main(int argc, char const *argv[])
{
    Employee e1 {1, "Bob"};
    Employee* e2 = new Employee {"Alice"};
    Employee e3 {2};
    e1.sayHello();
    e2->sayID();
    delete e2;
    
    // e1,e3会在main函数结束时自动调用析构函数,先e3后e1，因为e3是在e1之后创建的

    return 0;
}




