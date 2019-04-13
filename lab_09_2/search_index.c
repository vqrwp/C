//
// Created by Margo on 18.11.2018.
//

#include "search_index.h"
#include <string.h>

/*
Ищет индекс первого вхождения подстроки в текст

@param s [in] - текст, в котором ищем подстроку
@param t [in] - подстрока, которую ищем

@return возвращает индекс первого вхождения подстроки в текст если она входит, иначе -1
*/
int str_index(const char *s, const char *t)
{
    int i, j, k, lens = strlen(s), lent = strlen(t), flag = -1;
    for (i = 0; i < lens; i++)
    {
        if (flag == -1)
        {
            for (j = i, k = 0; k < lent && s[j] == t[k]; j++, k++);
            if (k > 0 && k == lent)
            {
                flag = i;
            }
        }
    }
    return flag;
}