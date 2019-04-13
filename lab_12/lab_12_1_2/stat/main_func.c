#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "mysort_lib.h"
#include "main_func.h"
#include "key_lib.h"

/**
Определяет количество цифр в файле.

@param fi [in]
@param count [out]
 
@return возвращает количество чисел в файле, если нет ошибок ввода, если ошибки есть - то -1.
*/
int counting_array(FILE *fi)
{
    int elem = 0, count = 0, rc = 0;
    char tmp;
    while (1)
    {
        while ((rc = fscanf(fi, "%d%c", &elem, &tmp)) != 2 && rc != EOF)
        {
            if (feof(fi))
                break;
            if (rc != EOF)
            {
                printf("Wrong symbols!");
                count = -1;
                break;
            }
        }
        count++;
        if (feof(fi))
            break;
        if (count == -1)
            break;
        if (tmp != ' ' && tmp != '\n')
        {
            printf("Wrong symbols!");
            count = -1;
            break;
        }
    }
    return count;
}

/**
Считывает числа из файла в массив.

@param fi [in]
@param pa [in]
@param count [in] 
*/
void reading_file(FILE *fi, int *pa, int count)
{
    int *num = pa;
    for (int i = 0; i < count; i++)
    {
        fscanf(fi, "%d", num);
        if (!i)
        {
            pa = num;
        }
        num++;
    }
}

/**
Копирует числа из массива в файл.

@param fo [in]
@param pa [in]
@param pb [in] 
*/
void print_in_file(FILE *fo, int *pa, int *pb)
{
    for (; pa < pb; pa++)
        fprintf(fo, "%d ", *pa);
}

/**
Освобождает всю использованную память.

@param fi [in]
@param fo [in]
@param pa [in]
*/
void free_n_close(FILE *fi, FILE *fo, int *pa)
{
    free(pa);
    fclose(fi);
    fclose(fo);
}

/**
Получает массив из файла, редактирует его (убирает элементы после первого отрицательного
и сортирует), затем выводит результат в другой файл.

@param fi [in]
@param fo [in]
@param pa [in]
@param pb [in]
@param f [in]
@param flag_big [out]
 
@return возвращает различные флаги ошибок, если все работает верно - то флаг = 0.
*/
int editing_array(int *pa, int *pb, FILE *fi, FILE *fo, char *f)
{
    int count = counting_array(fi), flag_big = 0;
    if (count != 1 && count != -1)
    {
        rewind(fi);
        reading_file(fi, pa, count);
        pb = pa + count;
        if (f && strcmp(f, "f") == 0)
        {
            int *pe = pa, *ps = pb;
            int flag = key(pa, pb, &pe, &ps);
            pa = pe;
            pb = ps;
            if (flag)
            {
                printf("Empty file after filter!");
                flag_big = -2;
            }
        }
        if (flag_big >= 0)
        {
            mysort(pa, pb, sizeof(int), compare_int);
        }
        print_in_file(fo, pa, pb);
    } else if (count != -1)
    {
        printf("Empty file!");
        flag_big = -1;
    }
    return flag_big;
}