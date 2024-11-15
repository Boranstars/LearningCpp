#include <cstdio>
#include <iostream>
#include <type_traits>


class Base
{
public:
    Base() = default;
    virtual void foo() = 0; // 纯虚函数, 没有函数体，只有声明，派生类必须实现这个函数。
    ~Base() = default;


};

class Derive : public Base
{
public:
    Derive() = default;
    void foo() override // 必须实现基类的纯虚函数
    {
        std::cout << "Derive::foo()" << std::endl;
    }
    ~Derive() = default;
};

// 纯虚函数也是虚函数，可以有函数体
void Base::foo() {
    std::cout << "Base::foo()" << std::endl;
} 

/**
 * @brief Log接口类
 * 如果一个类只有纯虚函数，那么这个类就是接口类
 */
class ILog
{
public:
    ILog() = default;
    virtual ~ILog() = default;
    virtual bool openLog(const char* filename) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeLog(const char* message) = 0;
    
private:
    
};

class FileLog : public ILog
{
public:
    FileLog() = default;
    ~FileLog() = default;
    bool openLog(const char* filename) override
    {
        std::cout << "FileLog::openLog()" << std::endl;
        return true;
    }
    bool closeLog() override
    {
        std::cout << "FileLog::closeLog()" << std::endl;
        return true;
    }
    bool writeLog(const char* message) override
    {
        std::cout << "FileLog::writeLog()" << std::endl;
        return true;
    }
};




int main(int argc, const char** argv) {
    // Base b1; // 错误，不能实例化抽象类
    Derive d1; // 正确，派生类实现了基类的纯虚函数

    Base *pb = new Derive();

    pb->foo(); // 输出Derive::foo()

    delete pb;


    FileLog fl;
    fl.openLog("test.log");
    fl.writeLog("Hello, World!");
    fl.closeLog();
    

    return 0;
}
