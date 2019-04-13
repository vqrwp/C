#include <malloc.h>
#include <stdio.h>
#include "key_lib.h"

/*
 * В массиве остаются элементы от нулевого до m-го, где m - индекс первого
отрицательного элемента этого массива либо число n (размер исходного массива), если
такого элемента в массиве нет. Т.е. отфильтрованный массив содержит элементы,
расположенные перед первым отрицательным элементом, или весь исходный массив,
если отрицательные элементы отсутствуют.
*/

/**
Переносит все числа массива до первого отрицательного в новый массив.

@param pb_src [in]
@param pe_src [in] 
@param pb_dst [in, out]
@param pe_dst [in, out]
@param flag [out]

@return если входные данные верны и программа работает корректно, то возвращает 0, иначе 1.
*/
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
// указатель на начало старого массива и конец нового массива, указатель на начало
// нового массива и на конец новго массива
{
    int flag = 1;
    if (pe_src <= pb_src)
        flag = 1;
    int count = 0, *base = (int*)pb_src;
    while (*pb_src >= 0 && pb_src < pe_src)
    {
        count++;
        pb_src++;
    }
    *pe_dst = *pb_dst + count;
    int *pa = *pb_dst;
    for (; pa < *pe_dst; pa++, base++)
    {
        *pa = *base;
        flag = 0;
    }
    return flag;
}