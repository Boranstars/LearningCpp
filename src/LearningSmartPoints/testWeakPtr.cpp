#include "Resource.hpp"
#include <memory>

class pairedResource : public Resource
{
private:
public:
    std::shared_ptr<pairedResource> m_ptr {};
    std::weak_ptr<pairedResource> m_weakPtr {};
    pairedResource(std::string name = "Default") : Resource(name) {};
    ~pairedResource() {}
public:
    const std::shared_ptr<pairedResource> getPtr() const
    {
        return this->m_weakPtr.lock(); // 使用weak_ptr的lock方法来获取shared_ptr对象, 因为weak_ptr无法直接访问资源
    }
};

int main(int argc, char const *argv[])
{
    auto pResPtr1 = std::make_shared<pairedResource>("pResPtr1");
    auto pResPtr2 = std::make_shared<pairedResource>("pResPtr2");


    
    // pResPtr1->m_ptr = pResPtr2;
    // // pResPtr2->m_ptr = pResPtr1; // 两个shared_ptr相互引用，导致资源无法释放，造成内存泄漏

    pResPtr1->m_weakPtr = pResPtr2;
    pResPtr2->m_weakPtr = pResPtr1; // 使用weak_ptr来解决shared_ptr相互引用的问题

    std::cout << *pResPtr1->getPtr() << std::endl;


    return 0;
}
