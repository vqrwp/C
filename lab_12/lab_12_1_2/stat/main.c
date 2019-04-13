#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "main_func.h"

int main(int argc, char* argv[])
{
    int flag_big = 0;
    if (argc < 3)
    {
        printf("Error in arguments!");
        flag_big = -3;
    }
    else
    {
        FILE *fi = fopen(argv[1], "r+");
        FILE *fo = fopen(argv[2], "w+");
        int *pa = (int *) malloc(1000 * sizeof(int)),
                *pb = NULL;
        if (!fi)
        {
            printf("Error in opening the file!");
            flag_big = -3;
        }
        else
        {
            char *f = malloc(10 * sizeof(char));
            flag_big = editing_array(pa, pb, fi, fo, argv[3]);
            free(f);
        }
        free_n_close(fi, fo, pa);
    }
    return flag_big;
}