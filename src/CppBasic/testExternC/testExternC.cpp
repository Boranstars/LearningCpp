#include <iostream>
#include <string>
#include <vector>
#include "cFunctions.h"
#if defined(__cplusplus)

extern "C" {
    #include <stdio.h>
    
#endif // __cplusplus)


#if defined(__cplusplus)
}
#endif // __cplusplus)





int main(int argc, char const *argv[])
{
    printf("Hello from C\n"); // Hello from C
    std::cout << "Hello from Cpp" << std::endl; // Hello from Cpp
    std::string str = "Hello C or Cpp!";
    std::vector<char> cStr(str.begin(), str.end()); // 将C++字符串转换为C字符串
    cStr.push_back('\0');
    // 现在我们调用C函数
    char* cstring = reverseString(cStr.data());
    printf("%s\n",cstring);
    std::cout << cStr.data() << std::endl;
    // std::cout << cStr << std::endl;
    return 0;
}
