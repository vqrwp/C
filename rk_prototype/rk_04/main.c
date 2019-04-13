#include <stdio.h>
#include "struct.h"
#include "print.h"
#include "task.h"

int main()
{
    FILE *f = fopen("rk.txt", "r+");
    FILE *fo = fopen("res.txt", "w+");
    t_city *list = NULL;

    if (f && fo)
    {
        read_struct(&list, f, fo);
        print_from_head(list, 0);
        char *city = malloc(sizeof(char) * 100);
        task(list, 0, 100000, city);
    }

    fclose(f);
    fclose(fo);
    return 0;
}