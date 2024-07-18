#include <iostream>
#include <string>
class testStaticMember
{
private:
    // 静态成员变量是类的所有对象共享的成员变量
    static int foo;
    int moo;
    //当静态成员是const整型类型(包括char和bool)或const enum时，可以在类定义中初始化静态成员
    static const int bar = 0;
    // C++17之后，非 const 静态成员也可以在类定义中内联地初始化
    static inline int ID = 0; 
    static std::string name; // 静态成员变量必须在类外初始化

    // static int getId() const; //静态类型函数不允许添加const限定符，因为静态类型对象没有this指针
    static int getID();
public:
    testStaticMember(/* args */) {}
    ~testStaticMember() {}
};
// 静态类成员可以在类外访问，即使是私有的
// 类外不需要加static
int testStaticMember::foo = 0; 

/**
 * @brief
 * 静态成员函数可以访问静态成员变量，但是不能访问非静态成员
 */
int testStaticMember::getID() 
{
    // return this->ID; // “this”只能用于非静态成员函数内部
    // moo;
    return ID;
}

