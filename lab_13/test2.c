#include "test2.h"

int test2()
{
    int flag = 0;
    FILE *fi = fopen("in_2.txt", "r+");
    FILE *res = fopen("res.txt", "w+");
    FILE *fo = fopen("out_2.txt", "r+");
    lect_t *list = NULL;

    LIST_HEAD(sort_by_age);
    LIST_HEAD(sort_by_department);
    head_t *sort_arr[MAX_SORT_INDX] = {&sort_by_age, &sort_by_department};

    LIST_HEAD(filter_by_age);
    LIST_HEAD(filter_by_department);
    LIST_HEAD(filter_by_subject);
    head_t *filter_arr[MAX_FILTER_INDX] = {&filter_by_age, &filter_by_department,
                                           &filter_by_subject};

    list = read_file(fi, list, sort_arr, filter_arr);

    del_rec(&list, 10);

    add_rec(&list, sort_arr, filter_arr, "FN12", "Matan", "Styrt", 32);

    save_in_file(res, list);

    rewind(res);
    rewind(fo);
    char buff[300], string[300];
    while (!feof(res))
    {
        fgets(buff, 300, res);
        fgets(string, 300, fo);
        if (strcmp(buff, string) != 0)
        {
            puts(buff);
            puts(string);
            flag = 1;
        }
    }


    fclose(fi);
    fclose(res);
    fclose(fo);
    return flag;
}