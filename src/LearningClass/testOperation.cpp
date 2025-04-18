#include <iostream>
#include <string>


class Foo
{
public:
    Foo() = default;
    Foo(Foo &&) = default;
    Foo(const Foo &) = default;
    Foo &operator=(Foo &&) = default;
    Foo &operator=(const Foo &) = default;
    ~Foo() = default;
    Foo(int i) : bar(i) {}

    /**
     * @brief 类中重载二元运算符，实际上是隐藏this指针，将this指针作为第一个参数传入。
     * 
     * @param rhs 
     * @return Foo 
     */
    Foo operator+(const Foo &rhs) const
    {
        Foo temp;
        temp.bar = this->bar + rhs.bar;
        return temp;
    }

    /**
     * @brief 使用友元重载二元运算符
     * 
     * @return Foo 
     */
    friend Foo operator-(const Foo& foo, int num)
    {
        Foo temp;
        temp.bar = foo.bar - num;
        return temp;
    };

    /**
     * @brief 重载前置++运算符,返回引用
     * 
     * @return Foo& 
     */
    Foo &operator++()
    {
        ++bar;
        return *this;
    }

    /**
     * @brief 重载后置++运算符
     * 
     * @return Foo 
     */
    Foo operator++(int)
    {
        Foo temp = *this;
        ++bar;
        return temp;
    }
    int bar = 0;
    int fooo {3};
private:
};

int main(int argc, const char** argv) {
    
    Foo foo1(1);

    Foo foo2(2);

    Foo foo3 = foo1 + foo2;

    Foo foo4 = foo1 - 1;

    Foo foo5 = foo1++;

    Foo foo6 = ++foo1;

    std::cout << "foo3.bar: " << foo3.bar << std::endl;
    std::cout << "foo4.bar: " << foo4.bar << std::endl;
    std::cout << "foo5.bar: " << foo5.bar << std::endl;
    std::cout << "foo6.bar: " << foo6.bar << std::endl;

    return 0;
}