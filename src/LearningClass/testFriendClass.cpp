#include <iostream>
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
    return 0;
}
