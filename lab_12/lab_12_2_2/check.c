#include "check.h"

int check(int *arr, FILE *f, int num_test)
{
    rewind(f);
    int flag = 1, x = 0, i = 0;
    while (!feof(f))
    {
        fscanf(f, "%d", &x);
        if (arr[i] != x)
        {
            printf("Test # %d: %d %d\n", num_test, x, arr[i]);
            flag = 0;
        }
        i++;
    }
    return flag;
}