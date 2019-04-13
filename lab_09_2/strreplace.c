#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "strcpy.h"
#include "search_index.h"
#include <math.h>

/*
Заменяет указанное слово в тексте на другое

@param source [in] - текст, слова в котором надо заменить
@param serach [in] - слово, которое надо заменить
@param replace [in] - слово, которым надо заменить
@param str [out] - строка с замененными словами

@return возвращает количество символов до найденного первого вхождения
*/
char* str_replace(const char *source, const char *serach, const char *replace)
{
    int len_source = strlen(source), len_repl = strlen(replace), len_serach = strlen(serach);
    char *str = "";
    int j = 0, diff = 0, index = 0, count = 0, flag = 0;
    index = str_index(source, serach);
    if (index == -1)
    {
        flag = -1;
    }
    while (index >= 0)
    {
        count++;
        str = realloc((void*)source, (size_t) ((len_source +
                count * abs(len_serach - len_repl)) + 1) * sizeof(char));
        for (j = 0; j < len_source + len_repl - len_serach; j++)
        {
            if (len_repl < len_serach)
            {
                diff = len_serach - len_repl;
            }
            if (j < index)
            {
                str[j] = source[j];
            }
            if (index <= j && j < index + len_repl)
            {
                str[j] = replace[j - index];
            }
            if (j >= index + len_repl && source[j + diff - 1] != '\n')
            {
                str[j] = source[j + diff];
                if (str[j] == '\n')
                {
                    str[j] = ' ';
                }
            }
        }
        index = str_index(source, serach);
    }
    char *string = malloc(10000 * sizeof(char));
    if (flag == 0)
    {
        my_strcpy(&string, str, j - count * diff + 1);
        return string;
    }
    else
    {
        return (char*)source;
    }
}