#include "check.h"
#include "strcspn.h"
#include "stdio.h"
#include "string.h"

/*
Сверяет результат работы библиотечной функции и моей

@param string1 [in] - первая строка
@param string2 [in] - вторая строка
@param flag [in,out] - маркер выполнения
@param count [in] - номер теста

@return вовращает 1, если выполнено верно и строки равны
*/
void check(const char *string1, const char *string2, int *flag, int count)
{
    if (strcspn(string1, string2) == my_strcspn(string1, string2))
    {
        *flag = 1;
    }
    else
    {
        printf("Failed test %d", count);
        printf("\n%d %d\n", strcspn(string1, string2), my_strcspn(string1, string2));
    }
}