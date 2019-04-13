#include "my_snprintf.h"
#include <stdarg.h>
#include "stdio.h"

/*
Добавляет подстроку в конец строки

@param sout [in] - строка, в которую производится добавление
@param num [in] - число, которое нужно добавить
@param base [in] - основание системы счисления
@param n [in] - максимальная длина строки
@param i [in] - индекс, с которого добавлять подстроку
@param j [out] - длина добавленной подстроки

@return Возвращает длину записанной подстроки
*/
int copy(char *sout, int num, int base, int n, int i)
{
    char *sin = malloc(n - 1 * sizeof(char));
    int j = 0;
    itoa(num, sin, base);
    while (sin[j])
    {
        sout[i] = sin[j];
        j++;
        i++;
    }
    free(sin);
    return j;
}

/*
Записывает определенное количество символов второй строки в первую, заменяя спецификаторы на числа

@param s [in] - строка, в которую производится считывание
@param n [in] - длина результирующей строки
@param format [in] - входная строка
@param flag [out] - код ошибки или количество переданных символов

@return Возвращает длину записанной строки или -1, если что-то пошло не так
*/
int my_snprintf(char *s, size_t n, const char *format, ...)
{
    int flag = 0;
    if (n == 0)
    {
        flag = -1;
    }
    else
    {
        int i = 0, j = 0, x;
        va_list vl;

        va_start(vl, format);

        while (format[i] != '\0' && j <= n - 1)
        {
            switch (format[i])
            {
                case '%':
                    switch (format[i + 1])
                    {
                        case 'x':
                            x = va_arg(vl, int);
                            j += copy(s, x, 16, n, j);
                            i += 2;
                            break;
                        case 'i':
                            x = va_arg(vl, int);
                            j += copy(s, x, 10, n, j);
                            i += 2;
                            break;
                        case 'o':
                            x = va_arg(vl, int);
                            j += copy(s, x, 8, n, j);
                            i += 2;
                            break;
                        case 'l':
                        {
                            switch (format[i + 2])
                            {
                                case 'x':
                                    x = va_arg(vl, int);
                                    j += copy(s, x, 16, n, j);
                                    i += 3;
                                    break;
                                case 'i':
                                    x = va_arg(vl, int);
                                    j += copy(s, x, 10, n, j);
                                    i += 3;
                                    break;
                                case 'o':
                                    x = va_arg(vl, int);
                                    j += copy(s, x, 8, n, j);
                                    i += 3;
                                    break;
                            }
                            break;
                        }
                    }

                default:
                    s[j] = format[i];
                    break;
            }
            i++;
            j++;
            if (format[i - 1] == '%' && (format[i] == 'i' || format[i] == 'x' || format[i] == 'o'))
            {
                i -= 1;
                j -= 1;
            }
            if (format[i - 1] == '%' && (format[i] == 'l'))
            {
                i -= 1;
                j -= 1;
            }
        }
        va_end(vl);
        if (j > n - 1)
        {
            s[n] = '\0';
            j = -1;
        }
        else
        {
            s[j] = '\0';
        }
        if (format[i] != '\0')
        {
            flag = -1;
        }
        else
        {
            flag = j;
        }
    }
    return flag;
}