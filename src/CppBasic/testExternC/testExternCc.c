#include "cFunctions.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char str[] = "Hello From C!";
    char *reversed = reverseString(str);
    printf("%s\n",reversed);
    return 0;
}
