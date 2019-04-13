#include "appendtest.h"
#include <stdio.h>
#include "struct.h"
#include "read_list.h"
#include "append.h"
#include "list_funcs.h"
#include "popend.h"

/*
Сравнивает значения двух списков

@param list [in] - первый список
@param res [in] - второй список

@return если верно, то 1, иначе 0
*/
int check(node_t **list, node_t **res)
{
    int flag = 1;
    while ((*list)->next && (*res)->next)
    {
        int *x = pop_back(list), *y = pop_back(res);
        if (*x != *y)
        {
            printf("append %d %d\n", *x, *y);
            flag = 0;
        }
    }
    return flag;
}

/*
Подает значения на проверку

@return если верно, то 1, иначе 0
*/
int appendtest()
{
    int flag1 = 0, flag2 = 0, flag3 = 0;

    FILE *f1 = fopen("in_1.txt", "r+");
    FILE *f2 = fopen("in_4.txt", "r+");
    FILE *f3 = fopen("in_5.txt", "r+");

    FILE *f11 = fopen("out_1.txt", "r+");
    FILE *f22 = fopen("out_2.txt", "r+");
    FILE *f33 = fopen("out_3.txt", "r+");

    if (f1 && f2 && f3 && f11 && f22 && f33)
    {
        node_t *res1 = NULL, *res2 = NULL, *res3 = NULL;
        read_list_int(&res1, f11);
        read_list_int(&res2, f22);
        read_list_int(&res3, f33);

        node_t *list1 = NULL;
        read_list_int(&list1, f3);
        node_t *list2 = NULL;
        read_list_int(&list2, f2);

        append(&list1, &list2);
        flag1 = check(&list1, &res1);

        list1 = NULL;
        read_list_int(&list1, f2);
        list2 = NULL;
        read_list_int(&list2, f3);

        append(&list1, &list2);
        flag2 = check(&list1, &res2);

        list1 = NULL;
        read_list_int(&list1, f1);
        list2 = NULL;
        read_list_int(&list2, f3);

        append(&list1, &list2);
        flag3 = check(&list1, &res3);
    }
    else
    {
        printf("Error in opening!\n");
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f11);
    fclose(f22);
    fclose(f33);
    return flag1 && flag3 && flag2;
}
