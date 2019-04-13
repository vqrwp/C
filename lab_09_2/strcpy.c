#include "strcpy.h"
#include <stdio.h>

/*
копирует одну строку в другую

@param string1 [in] - строка, в которую копируют
@param string2 [in] - строка, которую копируют
@param count [in] - длина строки, которую копируют

@return ничего не возвращает
*/
void my_strcpy(char **string1, const char *string2, int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        *(*string1 + i) = *(string2 + i);
    }
    if (*(*string1 + i - 1) == ' ')
    {
        *(*string1 + i - 1) = '\n';
    }
    else
    {
        *(*string1 + i) = '\n';
    }
}