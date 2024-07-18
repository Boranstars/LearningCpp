#include <string>


/**
 * @brief
 * 可以将类的声明和定义分开
 */
class testDefClass
{
private:
    int def1;
    std::string def2;
public:
    testDefClass() {}
    testDefClass(int def1, std::string def2) : def1(def1), def2(def2) {}
    /**
     * @brief
     * const修饰符表示该函数不会修改成员变量的值
     * 并且被const修饰的成员函数只能调用其他const成员函数
     * 但是const成员函数可以被非const成员函数调用
     * @return int
     * 
     */
    int getDef1() const;
    std::string_view getDef2() const ;
    void setDef2(std::string_view def2);

    ~testDefClass() {}
};