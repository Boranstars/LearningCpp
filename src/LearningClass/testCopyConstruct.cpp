#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

class Point {
  public:
    Point(double px = 0.0l, double py = 0.0l) : px(px), py(py) {
        std::cout << "含参构造函数被调用！创建了 " << *this << std::endl;
    };
    /**
     * @brief 移动构造函数
     * 移动构造函数，移动构造函数的参数是一个右值引用，右值引用是一个临时对象，临时对象是一个没有名字的对象，临时对象是一个右值。
     * 移动构造函数的作用是将一个右值引用的对象的资源转移到新的对象中，这样可以避免资源的拷贝，提高程序的效率。
     *
     * @param obj
     */
    Point(Point &&obj) noexcept : px(obj.px), py(obj.py) {
        std::cout << "移动构造函数被调用！创建了 " << *this;
        std::cout << "\n销毁了" << obj << std::endl;
        obj.px = 0;
        obj.py = 0;
    }
    /**
     * @brief 拷贝构造函数
     * 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类的另一个对象来初始化新创建的对象。
     *
     * @param obj
     */
    Point(const Point &obj) {
        this->px = obj.px;
        this->py = obj.py;
        std::cout << "拷贝构造函数被调用！创建了 " << *this << std::endl;
    }
    /**
     * @brief 移动赋值函数
     * 移动赋值函数，移动赋值函数的参数是一个右值引用，右值引用是一个临时对象，临时对象是一个没有名字的对象，临时对象是一个右值。
     * 移动赋值函数的作用是将一个右值引用的对象的资源转移到新的对象中，这样可以避免资源的拷贝，提高程序的效率。
     *
     * @param obj
     * @return Point&
     */
    Point &operator=(Point &&obj) noexcept {
        this->px = obj.px;
        this->py = obj.py;
        std::cout << "移动赋值函数被调用！通过 " << obj << " 创建了 " << *this
                  << std::endl;
        std::cout << "销毁了" << obj << std::endl;
        obj.px = 0;
        obj.py = 0;
        return *this;
    }
    /**
     * @brief 拷贝赋值函数
     * 拷贝赋值函数是一种特殊的赋值函数，它在用同一类的另一个对象来赋值新创建的对象时调用。
     *
     * @param obj
     * @return Point&
     */
    Point &operator=(const Point &obj) {
        if (this != &obj) {
            // 避免自我赋值
            this->px = obj.px;
            this->py = obj.py;
            std::cout << "拷贝赋值函数被调用！通过 " << obj << " 创建了 "
                      << *this << std::endl;
        } else {
            std::cout << *this << "自我赋值！" << std::endl;
        }
        return *this;
    }
    ~Point();
    /**
     * @brief 重载输出运算符
     *
     * @param os
     * @param point
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "Ponits(" << point.px << ", " << point.py << ")"
           << "address: " << &point;
        return os;
    }

  private:
    double px;
    double py;
};

Point::~Point() {}

int main(int argc, const char **argv) {
    Point p1(1, 2);
    Point p2(p1);
    Point p3 = p1;
    Point p4;
    p4 = p1;
    p4 = p4;
    auto ptr1 = std::make_shared<Point>(3, 4);
    Point p5 = std::move(*ptr1);
    Point p6;
    p6 = std::move(p5);
    p6 = std::move(p6);
    return 0;
}