#include "print_struct.h"
#include <stdio.h>
#include "counting_words_in_file.h"

void print_struct(FILE *f, num_words *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%30s ", arr[i].string);
        fprintf(f, "%3d\n", arr[i].num);
    }
}