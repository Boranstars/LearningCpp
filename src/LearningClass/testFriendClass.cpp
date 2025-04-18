#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class testFriendClass;
class friendClass
{
public:
    friendClass(){};
    ~friendClass(){};
    void printObject(const testFriendClass &tfC);

private:
};

class testFriendClass
{

private:
    int _ID;
    std::string _name;
    friend void friendClass::printObject(const testFriendClass& tfC);

public:
    // friend class friendClass;
    testFriendClass();
    testFriendClass(int ID, std::string name);
    friend std::ostream &operator<<(std::ostream &os, const testFriendClass &tfC)
    {
        os << tfC._ID << " " << tfC._name;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, testFriendClass &tfC)
    {
        is >> tfC._ID >> tfC._name;
        return is;
    }
    ~testFriendClass();
};


void friendClass::printObject(const testFriendClass &tfC)
{
    std::cout << tfC._ID << std::endl;
};

testFriendClass::testFriendClass()
{
}

testFriendClass::testFriendClass(int ID, std::string name) : _ID(ID), _name(name)
{
}

testFriendClass::~testFriendClass()
{
}

int main(int argc, char const *argv[])
{
    testFriendClass tfC1(114514, "TANAKA");
    friendClass fC1;
    fC1.printObject(tfC1);
    std::cout << tfC1 << std::endl;
    std::cin >> tfC1;
    std::cout << tfC1 << std::endl;
    return 0;
}
