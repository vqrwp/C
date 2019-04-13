#include "sorttest.h"
#include <stdio.h>
#include "struct.h"
#include "read_list.h"
#include "insert_sort.h"
#include "list_funcs.h"
#include "popend.h"

/*
Сравнивает значения двух списков

@param list [in] - первый список
@param res [in] - второй список

@return если верно, то 1, иначе 0
*/
int check_sort(node_t **list, node_t **res)
{
    int flag = 1;
    while ((*list)->next && (*res)->next)
    {
        int *x = pop_back(list), *y = pop_back(res);
        if (*x != *y)
        {
            printf("sort %d %d\n", *x, *y);
            flag = 0;
        }
    }
    return flag;
}

/*
Подает значения на проверку

@return если верно, то 1, иначе 0
*/
int sorttest()
{
    int flag1 = 0, flag2 = 0, flag3 = 0;

    FILE *f1 = fopen("in_1.txt", "r+");
    FILE *f2 = fopen("in_4.txt", "r+");
    FILE *f3 = fopen("in_5.txt", "r+");

    FILE *f11 = fopen("out_4.txt", "r+");
    FILE *f22 = fopen("out_5.txt", "r+");
    FILE *f33 = fopen("out_6.txt", "r+");

    if (f1 && f2 && f3 && f11 && f22 && f33)
    {
        node_t *res1 = NULL, *res2 = NULL, *res3 = NULL;
        read_list_int(&res1, f11);
        read_list_int(&res2, f22);
        read_list_int(&res3, f33);

        node_t *list1 = NULL;
        read_list_int(&list1, f1);
        node_t *list2 = NULL;
        read_list_int(&list2, f2);
        node_t *list3 = NULL;
        read_list_int(&list3, f3);

        node_t *new1 = NULL;
        new1 = sort(list1, comparator_int);

        flag1 = check_sort(&new1, &res1);

        node_t *new2 = NULL;
        new2 = sort(list2, comparator_int);

        flag2 = check_sort(&new2, &res2);

        node_t *new3 = NULL;
        new3 = sort(list3, comparator_int);

        flag3 = check_sort(&new3, &res3);
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
