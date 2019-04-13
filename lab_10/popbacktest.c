#include "popbacktest.h"
#include "read_list.h"
#include "popend.h"
#include <stdio.h>

/*
Подает значения на проверку

@return если верно, то 1, иначе 0
*/
int popbacktest()
{
    int flag = 1;
    FILE *f = fopen("in_1.txt", "r+");
    node_t *list = NULL;
    read_list_int(&list, f);
    int *x = pop_back(&list);
    if (*x != 8)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    x = pop_back(&list);
    if (*x != 3)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    x = pop_back(&list);
    if (*x != 4)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    fclose(f);
    FILE *f1 = fopen("in_2.txt", "r+");
    list = NULL;
    read_list_char(&list, f1);
    char *c = pop_back(&list);
    c = pop_back(&list);
    if (*c != 'e')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    c = pop_back(&list);
    if (*c != 'r')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    c = pop_back(&list);
    if (*c != 'g')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    fclose(f1);
    return flag;
}
