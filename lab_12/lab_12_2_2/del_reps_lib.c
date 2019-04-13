#include "del_reps_lib.h"

/*
2. Реализовать функцию, которая из одного массива помещает во второй массив первое
вхождение каждого элемента первого массива.
*/

/**
Из одного массива помещает во второй массив первое вхождение каждого элемента первого массива

@param arr [in] - указатель на исходный массив
@param n [in] - длина исходного массива
@param new_arr [in,out] - указатель на результирующий массив
@param new_len [out] - длина результирующего массива

@return возвращает количество элементов в итоговом массиве если успешно,
0 если возникли ошибки (пустой первый массив)
*/
FUNC_DLL int FUNC_DECL del_reps(const int *arr, int n, int *new_arr)
{
    int new_len = n, flag = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == new_arr[j] && i != j)
            {
                new_len--;
                flag = 1;
            }
        }
        if (flag != 1)
        {
            new_arr[count] = arr[i];
            count++;
        }
    }
    if (new_len < 0)
    {
        new_len = 0;
    }
    return new_len;
}