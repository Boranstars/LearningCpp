#include "Resource.hpp"
#include <memory>

int main(int argc, char const *argv[])
{
    Resource *res = new Resource;
    std::shared_ptr<Resource> resP{res};
    {
        std::cout << "\t---Enter CodeSpace 1---" << std::endl;
        std::shared_ptr<Resource> anotherResP{resP}; // 如果这里直接从原始指针创建shared_ptr，会导致资源被释放两次，因为两个shared_ptr都会尝试释放资源
        std::cout << "Killing one shared pointer\n";
        std::cout << "\t---Leave CodeSpace 1---" << std::endl;
    }
    std::cout << "Killing another shared pointer\n";

    auto resPtr1 = std::make_shared<Resource>("resPtr1");
    {
        std::cout << "\t---Enter CodeSpace 2---" << std::endl;
        auto resPtr2 = resPtr1;
        std::cout << "Killing one shared pointer\n";
        std::cout << "\t---Leave CodeSpace 2---" << std::endl;
    }
    std::cout << "Killing another shared pointer\n";
    return 0;
}
