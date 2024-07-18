#include <iostream>

class testThisPointer
{
private:
    int foo;
    const char* bar;
public:
    testThisPointer(int foo, const char* bar) : foo(foo), bar(bar){};
    void printThisPointer()
    {   

        // this指针是一个指向当前对象的指针
        // this指针是一个隐式的参数，是成员函数的一部分
        // this指针是一个常量指针，不能修改指向的对象
        std::cout << "this pointer: " << this  << this->bar << this->foo << std::endl;
    }

    ~testThisPointer(){};
};


class MultiCallSelf
{
private:
    int value;
public:
    MultiCallSelf(int value) : value(value) {}

    /**
     * @brief
     * 后置const修饰符表示该函数不会修改成员变量的值
     */
    int getValue() const { return value; }


    /**
     * @brief
     * 返回*this的引用，可以实现多次调用
     * @return MultiCallSelf& 
     */
    MultiCallSelf& plus(int value) {
        this->value += value;
        return *this;
    }

    MultiCallSelf& minus(int value) {
        this->value -= value;
        return *this;
    }

    MultiCallSelf& multiply(int value) {
        this->value *= value;
        return *this;
    }

    
    ~MultiCallSelf() {}
};

int main(int argc, char const *argv[])
{
    testThisPointer test(1, "test");
    test.printThisPointer();
    MultiCallSelf mcs{10};
    std::cout << mcs.plus(5).minus(3).multiply(2).getValue() << std::endl;

    return 0;
}



