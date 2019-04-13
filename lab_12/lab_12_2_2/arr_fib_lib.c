#include "arr_fib_lib.h"

/*
Вариант 2
1. Реализовать функцию заполнения массива числами Фибоначчи.
*/

/**
Заполняет массив числами Фибоначчи

@param arr [in,out] - указатель на массив
@param n [in] - длина массива

@return возвращает указатель на массив длины н, заполненный числами Фибоначчи
*/
FUNC_DLL int* FUNC_DECL fib_arr(int *arr, int n)
{
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    return arr;
}

