#include <iostream>
#include <string>

class Base {
  public:
    Base() = default;
    virtual ~Base() {
        std::cout << "Base is destroyed" << std::endl;
    }; // 析构函数是虚函数，会被派生类覆盖。这样可以保证在delete基类指针时，会调用派生类的析构函数。
    std::string getNameNoVrtl() {
        return "Base";
    } // 这个函数不是虚函数，不会被派生类覆盖。
    virtual std::string getName() {
        return "Base";
    } // 这个函数是虚函数，会被派生类覆盖。
  private:
};



class Derive : public Base {
  public:
    Derive() = default;
    virtual ~Derive() override {
        std::cout << "Derive is destroyed" << std::endl;
    }; // 析构函数是虚函数，会被派生类覆盖。这样可以保证在delete基类指针时，会调用派生类的析构函数。
    std::string getNameNoVrtl() {
        return "Derive";
    } // 这个函数不是虚函数，不会被派生类覆盖。
    std::string getName() override final {
        return "Derive";
    } // 这个函数是虚函数，会被派生类覆盖。
    // Override关键字是C++11引入的，用于显式地告诉编译器这个函数是一个覆盖函数。(覆盖基类的虚函数)
    // final关键字是C++11引入的，用于显式地告诉编译器这个函数是一个不能被覆盖的函数。（不能被派生类覆盖）
  private:
};

int main(int argc, const char **argv) {


    Base *pb1 = {new Base()};
    std::cout << pb1->getNameNoVrtl() << std::endl; // 输出Base
    std::cout << pb1->getName() << std::endl;
    pb1 = new Derive(); // 派生类对象的地址赋给基类指针, 会调用基类的函数。
    std::cout << pb1->getNameNoVrtl() << std::endl;             // 输出Base
    std::cout << ((Derive *)pb1)->getNameNoVrtl() << std::endl; // 输出Derive
    std::cout << pb1->getName() << std::endl;                   // 输出Derive
    delete pb1; // 虚析构函数会调用派生类的析构函数。
    return 0;
}