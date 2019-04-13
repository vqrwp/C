#include <stdio.h>
#include <string.h>
#include "check.h"

// variant 3  strcspn

int main()
{
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, count = 0;
    check("asdfgh", "9999991a", &flag1, count++);
    check("assdfgh", "99s99991a", &flag2, count++);
    check("    a", "a ", &flag3, count++);
    check("", "ab", &flag4, count++);
    check("", "", &flag5, count);
    if (flag1 && flag2 && flag3 && flag4 && flag5)
    {
        printf("Correct!");
    }
    return 0;
}