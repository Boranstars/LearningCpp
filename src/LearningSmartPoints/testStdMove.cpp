/**
 * @file testStdMove.cpp
 * @brief 本文件演示了如何使用std::move进行移动语义交换
 * 
 * std::move是一个标准库函数模板，用于将对象转换为右值引用，从而启用移动语义。
 * 移动语义允许资源（如动态内存、文件句柄等）的所有权从一个对象转移到另一个对象，
 * 而不需要进行昂贵的深拷贝操作。通过std::move，可以显著提高程序的性能，特别是在
 * 处理大量数据或资源密集型操作时。
 * 
 * 在本示例中，mySwapMove函数使用std::move来交换两个对象的值，而不进行拷贝操作。
 * 这使得交换操作更加高效，因为它避免了不必要的资源分配和释放。
 */
#include "Resource.hpp"
#include <vector>



/**
 * @brief 拷贝交换
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template<class T>
void mySwapCopy(T &a, T &b)
{
    T temp { a };
    std::cout << temp << std::endl;
    a = b;
    b = temp;
}

/**
 * @brief 移动语义交换
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template<class T>
void mySwapMove(T &a, T &b)
{
    T temp { std::move(a) };
    std::cout << temp << std::endl;
    a = std::move(b);
    b = std::move(temp);

}
int main(int argc, char const *argv[])
{
    Resource rs1("Rs1");
    Resource rs2("Rs2");
    Resource rs3("Rs3");
    Resource rs4("Rs4");
    Resource rs5("Rs5");
    Resource *rsp1 = new Resource("Rsp");
    Resource *rsp2 = new Resource("Rsp2");
    Resource *rsp3 = new Resource("Rsp3");
    Resource *rsp4 = new Resource("Rsp4");
    Resource *rsp5 = new Resource("Rsp5");

    std::vector<Resource> vecRes;
    // mySwapCopy<Resource>(rs1, rs2);
    mySwapMove<Resource>(rs1, rs2);
    std::cout << rs1 << "\n" << rs2 << std::endl;


    // 手动管理资源的情况
    delete rsp1;
    delete rsp2;
    delete rsp3;
    delete rsp4;
    delete rsp5;
    return 0;
}
