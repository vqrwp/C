#include <stdio.h>
#include <stdlib.h>
#include "del_reps_lib.h"
#include "arr_fib_lib.h"
#include "check.h"

int main()
{
    FILE *f1 = fopen("out_1.txt", "r+");
    FILE *f2 = fopen("out_2.txt", "r+");
    FILE *f3 = fopen("out_3.txt", "r+");
    FILE *f4 = fopen("out_4.txt", "r+");

    int *arr = malloc(10 * sizeof(int));
    int arr_1[8] = {5, 6, 5, 7, 8, 7, 5, 6}, arr_2[8] = {1, 1, 2, 1, 2, 3, 1, 5};
    int *arr_3 = malloc(10 * sizeof(int)), *arr_4 = malloc(10 * sizeof(int));
    int n1 = 8, n2 = 6, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;

    fib_arr(arr, n1);
    flag1 = check(arr, f1, 1);

    fib_arr(arr, n2);
    flag2 = check(arr, f2, 2);

    n1 = del_reps(arr_1, 8, arr_3);
    flag3 = check(arr_3, f3, 3);

    n1 = del_reps(arr_2, 8, arr_4);
    flag4 = check(arr_4, f4, 4);

    if (flag1 && flag2 && flag3 && flag4)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Wrong!\n");
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    free(arr);
    free(arr_3);
    free(arr_4);
}

