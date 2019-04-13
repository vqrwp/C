#include <stdio.h>
#include <malloc.h>
#include "my_snprintf.h"

/*
Реализовать собственную версию функции snprintf, обрабатывающую указанные
спецификаторы типа. Функция должна называться my_snprintf. При реализации этой
функции запрещается использовать любые стандартные функции для обработки строк.

 %x
Шестнадцатеричное число без знака (строчные буквы)
 %i
Десятичное целое число со знаком
 %o
 Восьмеричное число без знака
 %lx %li %lo
*/

int main()
{
    size_t n = 60;
    char *s = malloc((n + 1) * sizeof(char)), *t = malloc((n + 1) * sizeof(char));
    int num = snprintf(s, n, "Hello, number %x %i %o %lx %li %lo!",
             -3000, -3000, 3000, (unsigned long)-3000, (long)-3000, (unsigned long)-3000);
    puts(s);
    printf("%d\n", num);

    num = my_snprintf(t, n, "Hello, number %x %i %o %lx %li %lo!",
                -3000, -3000, 3000, (unsigned long)-3000, (long)-3000, (unsigned long)-3000);
    puts(t);
    printf("%d\n", num);
    return 0;
}