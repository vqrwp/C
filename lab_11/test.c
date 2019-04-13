#include "my_snprintf.h"
#include <stdio.h>
#include <string.h>

int main()
{
    size_t n = 100, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    char *s = malloc((n + 1) * sizeof(char)), *t = malloc((n + 1) * sizeof(char));
    int num = snprintf(s, n, "Hello, number %x %i %o %lx %li %lo!",
                       -3000, -3000, 3000, (unsigned long)-3000, (long)-3000, (unsigned long)-3000);

    int num1 = my_snprintf(t, n, "Hello, number %x %i %o %lx %li %lo!",
                      -3000, -3000, 3000, (unsigned long)-3000, (long)-3000, (unsigned long)-3000);
    if (strcmp(s, t) == 0 && num == num1)
    {
        flag1 = 1;
    }

    num = snprintf(s, n, "Hello, number %x %x %x %lx %lx %lx!",
                       -5000, -5000, 5000, (unsigned long)-5000, (long)-5000, (unsigned long)-5000);

    num1 = my_snprintf(t, n, "Hello, number %x %x %x %lx %lx %lx!",
                           -5000, -5000, 5000, (unsigned long)-5000, (long)-5000, (unsigned long)-5000);
    if (strcmp(s, t) == 0 && num == num1)
    {
        flag2 = 1;
    }
    printf("Test1: %d\n", flag1);

    num = snprintf(s, n, "Hello, number %x %x %x %lx %lx %lx!",
                   -5000, -6000, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);

    num1 = my_snprintf(t, n, "Hello, number %x %x %x %lx %lx %lx!",
                       -5000, -6000, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);
    if (strcmp(s, t) == 0 && num == num1)
    {
        flag2 = 1;
    }
    printf("Test2: %d\n", flag2);

    num = snprintf(s, n, "Hello, number %i %i %i %li %li %li!",
                   -5000, -6000, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);

    num1 = my_snprintf(t, n, "Hello, number %i %i %i %li %li %li!",
                       -5000, -6000, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);
    if (strcmp(s, t) == 0 && num == num1)
    {
        flag3 = 1;
    }
    printf("Test3: %d\n", flag3);

    num = snprintf(s, n, "Hello, number %o%o%o%lo%lo%lo!",
                   0, 0, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);

    num1 = my_snprintf(t, n, "Hello, number %o%o%o%lo%lo%lo!",
                       0, 0, 7000, (unsigned long)-5000, (long)-6000, (unsigned long)-7000);
    if (strcmp(s, t) == 0 && num == num1)
    {
        flag4 = 1;
    }
    printf("Test4: %d\nHello, number %%o%%o%%o%%lo%%lo%%lo!\n%s\n%s\n\n", flag4, s, t);

    if (flag1 && flag2 && flag3 && flag4)
    {
        printf("Correct!");
    }
    else
    {
        printf("Mistake!");
    }
}