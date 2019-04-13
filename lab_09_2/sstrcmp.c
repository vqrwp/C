#include "sstrcmp.h"
#include <stdio.h>

/*
сравнивает две строки, не учитывая пробельные символы

@param string1 [in] - первая строка
@param string2 [in] - вторая строка
@param flag [out] - результат

@return возвращает 0 если все символы совпали, иначе -1
*/
int my_strcmp(const char *string1, const char *string2)
{
    int flag = 0;
    for (int i = 0; string1[i]; i++)
    {
        if (string1[i] != string2[i] && string1[i] != ' ' && string2[i] != ' '
            && string1[i] != '\n' && string2[i] != '\n')
        {
            flag = -1;
        }
    }
    return flag;
}