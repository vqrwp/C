#include <stdio.h>
#include "getline.h"
#include "malloc.h"
#include "strcpy.h"
#include <string.h>

/**
Считывает строку из файла с помощью дополнительного буфера

@param lineptr [in] - строка, в которую производится считывание
@param n [out] - длина результирующей строки
@param stream [in] - входной файл

@return Возвращает длину записанной в процессе считывания из файла строки
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    int size_buf = 129;
    ssize_t difference = 0;
    char *buff = calloc((size_t) (size_buf), sizeof(char));
    fgets(buff, size_buf, stream);
    int len = strlen(buff);
    *lineptr = realloc(*lineptr, (*n + len + 1) * sizeof(char));
    if (*lineptr)
    {
        strncat(*lineptr, buff, (size_t) len);
        *n += len;
        difference += len;
    }
    else
    {
        difference = -1;
    }
    free(buff);
    return difference;
}