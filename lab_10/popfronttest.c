#include "popfronttest.h"
#include <stdio.h>
#include "struct.h"
#include "read_list.h"
#include "popfront.h"

/*
Подает значения на проверку

@return если верно, то 1, иначе 0
*/
int popfronttest()
{
    int flag = 1;
    FILE *f = fopen("in_1.txt", "r+");
    node_t *list = NULL;
    read_list_int(&list, f);
    int *x = pop_front(&list);
    if (*x != 7)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    x = pop_front(&list);
    if (*x != 1)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    x = pop_front(&list);
    if (*x != 2)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    fclose(f);
    FILE *f1 = fopen("in_2.txt", "r+");
    list = NULL;
    read_list_char(&list, f1);
    char *c = pop_front(&list);
    if (*c != 'g')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    c = pop_front(&list);
    if (*c != 'h')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    c = pop_front(&list);
    if (*c != 'j')
    {
        printf("%c\n", *c);
        flag = 0;
    }
    fclose(f1);
    return flag;
}
