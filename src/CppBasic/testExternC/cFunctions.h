#if !defined(__CPPBASIC_TESTEXTERNC_CFUNCTIONS_H__)
#define __CPPBASIC_TESTEXTERNC_CFUNCTIONS_H__

/**
 * __cplusplus 是一个预定义的宏，用于检测当前代码是否是C++代码
 */
#if defined(__cplusplus)
/**
 * 如果当前代码是C++代码，则需要使用extern "C"来声明C函数
 * 这种形式可以让这个代码在c和cpp中通用，而不用特定指定接口，直接导入即可
 */
extern "C" {
#endif // __cplusplus

/**
 * @brief C函数，用于反转字符串
 * 
 * @param str 
 * @return char* 
 */
char* reverseString(char str[]);




#if defined(__cplusplus)
/**
 * 如果当前代码是C++代码，则需要使用extern "C"来声明C函数
 */
}
#endif // _cplusplus

#endif // __CPPBASIC_TESTEXTERNC_CFUNCTIONS_H__
