#include "cFunctions.h"
// #include <stdio.h>
#include <stdlib.h>
// #include <string.h>
/**
 * @brief C函数，用于反转字符串
 * 
 * @param str 
 * @return char* 
 */
char* reverseString(char str[])
{
    // int start = 0;
    // int end = strlen(str) - 1;
    // while (start < end)
    // {
    //     char temp = str[start];
    //     str[start] = str[end];
    //     str[end] = temp;
    //     start++;
    //     end--;
    // }
    // return str;

    // 用指针实现，计算字符串长度
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    // 创建一个新的字符串
    char *newStr = (char *)malloc(len + 1);
    // 反转字符串
    for (int i = 0; i < len; i++)
    {
        newStr[i] = str[len - i - 1];
    }
    newStr[len] = '\0';
    return newStr;

  
    
}
