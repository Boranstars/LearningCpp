#if !defined(__RESOURCE_HPP)
#define __RESOURCE_HPP
#include <iostream>
class Resource
{
private:
    std::string _name;
    
public:
    Resource(std::string name = "Default"): _name(name) {
        
        std::cout << this->_name << " acquired, Address: " << this << std::endl;
        
    }
    ~Resource() {
        std::cout << this->_name << " distoryed. Prev address: " << this << std::endl;
        
    }

    friend std::ostream& operator<<(std::ostream& os, const Resource& res)
    {
        os << "Resource(Name: " << res._name << "), Address: " << &res;
        return os;
    }
};





#endif // __RESOURCE_HPP


