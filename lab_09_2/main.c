#include <stdio.h>
#include <malloc.h>
#include "getline.h"
#include "strreplace.h"

int main(int argc, char **argv)
{
    char *str = (char*)calloc(sizeof(char), 128);
    size_t size = 0;
    FILE *f = fopen(argv[1], "r+");
    FILE *f1 = fopen(argv[2], "w+");
    int flag = 0, i = 0;
    if (f && f1)
    {
        while (!feof(f))
        {
            my_getline(&str, &size, f);
            str = str_replace(str, argv[3], argv[4]);
        }
        fprintf(f1, "%s", str);
    }
    else
    {
        flag = -2;
    }
    fclose(f);
    fclose(f1);
    free(str);
    return flag;
}