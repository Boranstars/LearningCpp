#include "Resource.hpp"
#include <memory>

std::unique_ptr<Resource> createRes() 
{
    return std::make_unique<Resource>("tempRes");
}

void takeOwnship(std::unique_ptr<Resource> res)
{
    if (res)
    {
        std::cout << *res << std::endl;
    }
    
}
int main(int argc, char const *argv[])
{   
    
    std::unique_ptr<Resource> res { new Resource() }; // unique_ptr是一个独占指针，只能有一个指针指向资源, 不能进行拷贝，所以不能使用=进行赋值
    
    std::unique_ptr<Resource> resOther = std::make_unique<Resource>(); // 可以使用make_unique来创建unique_ptr对象，更加安全。


    auto res1 = std::make_unique<Resource>("Res1"); // 配合auto关键字使用，可以简化代码，不需要显式指定类型。
    std::cout << "\t---Start resList---\t" << std::endl;
    auto resList = std::make_unique<Resource[]>(5); // 定义一个Resource类型的数组，长度为5
    std::cout << "\t---End resList---\t" << std::endl;

    auto tempRes = createRes();
    // takeOwnship(tempRes); // 不能传递临时对象，因为临时对象会在函数调用结束后被销毁，导致资源泄漏, 但是可以使用std::move来传递临时对象
    takeOwnship(std::move(tempRes)); // 使用std::move来传递临时对象，这样就可以将临时对象的所有权转移给函数，避免资源泄漏。

    // std::unique_ptr<Resource> res2 {res}; // 不能进行拷贝，因为unique_ptr是一个独占指针，只能有一个指针指向资源 

    // delete res; // unique_ptr不能使用delete来释放资源，因为unique_ptr会自动释放资源，所以不需要手动释放资源。

    std::cout << "\t---End of main code---\t" << std::endl;
    return 0;
}
