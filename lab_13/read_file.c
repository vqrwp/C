#include "read_file.h"

void fill_num(int *num, char *string, int fl)
{
    char *s = (char *) malloc(sizeof(char) * 250);
    *num = (int) strtoll(string, &s, 10);
    if (fl)
    {
        strcpy(string, s);
        int k = 0;
        for (; k < strlen(string) - 2; k++)
        {
            string[k] = string[k + 2];
        }
        string[k] = '\0';
    }
}

void fill_str(char *pString, char *string)
{
    int j = 0, k = 0;
    for (j = 0; string[j] != ';'; j++)
    {
        pString[j] = string[j];
    }
    pString[j] = '\0';
    j += 2;
    for (k = 0; k < j, k < strlen(string); k++)
    {
        string[k] = string[k + j];
    }
    string[k] = '\0';
}

void add_berkli(lect_t *new_elem, head_t **sort_arr, head_t **filter_arr)
{
    add_to_sort(new_elem, sort_arr[0], 0, compare_ints);
    add_to_sort(new_elem, sort_arr[1], 1, compare_strings);
    if (new_elem->age <= OLDEST)
    {
        list_add_tail(&new_elem->filter[0], filter_arr[0]);
    }
    if (strstr(new_elem->department, FACULTY))
    {
        list_add_tail(&new_elem->filter[1], filter_arr[1]);
    }
    if (strstr(new_elem->subject, SUBJ))
    {
        list_add_tail(&new_elem->filter[2], filter_arr[2]);
    }
}

lect_t *read_file(FILE *f, lect_t *list, head_t **sort_arr, head_t **filter_arr)
{
    while (!feof(f))
    {
        lect_t *new_elem = malloc(sizeof(lect_t));
        new_elem->next = NULL;
        new_elem->age = 0;

        char string[40] = "";
        fgets(string, 40, f);

        fill_str(new_elem->department, string);
        fill_str(new_elem->lecturer, string);
        fill_str(new_elem->subject, string);
        fill_num(&(new_elem->age), string, 0);

        list = push_node(list, new_elem);

        add_berkli(new_elem, sort_arr, filter_arr);
        fflush(stdin);
    }
    return list;
}