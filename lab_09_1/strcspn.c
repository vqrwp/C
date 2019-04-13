#include <stdio.h>
#include "strcspn.h"
#include "strlen.h"

/*
Выполняет поиск первого вхождения в строку string1 любого из символов строки string2

@param string1 [in] - первая строка
@param string2 [in] - вторая строка
@param res [out] - количество символов до найденного первого вхождения

@return возвращает количество символов до найденного первого вхождения
*/
unsigned int my_strcspn(const char *string1, const char *string2)
{
    unsigned int res = 0, flag = 0, i = 0, j = 0;
    unsigned int len1 = my_strlen(string1), len2 = my_strlen(string2);
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
             if (string1[i] == string2[j] && flag == 0)
             {
                 flag = 1;
                 res = i;
             }
        }
    }
    if (flag == 0)
    {
        res = len1;
    }
    return  res;
}