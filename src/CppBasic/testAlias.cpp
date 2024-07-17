#include <iostream>
#include <string>
#include <vector>
// 使用using定义别名
using distance_t = double; // 别名
using string_t = std::string; // 别名
distance_t distance = 10.0; // 使用别名
string_t name = "hello"; // 使用别名

// 使用typedef定义别名,但是不推荐使用，C语言中使用
typedef double distance_t2; // 别名
typedef std::string string_t2; // 别名

// 使用using定义模板别名
template<typename T>
using vector_t = std::vector<T>; // 模板别名

// 使用using使用途更清晰
using studentScore = int;