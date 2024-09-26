#include <iostream>

class Base
{
private:
   int privateVar; 
   // private成员变量只能在类内部访问
public:
    int publicVar;
    // public成员变量可以在类内部和类外部访问
protected:
    int protectedVar;
    // protected成员变量可以在类内部和派生类中访问
};