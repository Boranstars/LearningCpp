#include <functional>
#include <iostream>
#include <string>
#include <thread>
/**
 * @brief 函数指针线程
 * 
 * @param msg 
 */
void func(std::string msg) {
    std::cout << "fucntion poiner thread, msg:" << msg << std::endl;
}
/**
 * @brief 仿函数线程
 * 
 */
struct functor {
    void operator()(std::string msg) {
        std::cout << "functor thread, msg:" << msg << std::endl;
    }
};
/**
 * @brief 成员函数线程
 * 
 */
class testClass {
  public:
    testClass() = default;
    testClass(testClass &&) = default;
    testClass(const testClass &) = default;
    testClass &operator=(testClass &&) = default;
    testClass &operator=(const testClass &) = default;
    ~testClass() = default;

    void meberfuc(std::string msg) {
        std::cout << "member function thread, msg:" << msg << std::endl;
    }

  private:
};

int main(int argc, const char **argv) {

    std::string msg = "yup!";
    std::thread funcThread(func, msg);
    testClass ts;
    std::thread memberThread(&testClass::meberfuc, &ts, msg);
    functor f;
    std::thread functorThread(f, msg);
    // lambda表达式线程
    std::thread lambdaThread(
        [](std::string msg) -> void {
            std::cout << "lambda Thread, msg:" << msg << std::endl;
        },
        msg
    );
    // 等待所有线程结束
    funcThread.join();
    memberThread.join();
    functorThread.join();
    lambdaThread.join();
    return 0;
}