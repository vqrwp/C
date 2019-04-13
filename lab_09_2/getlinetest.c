#include "getlinetest.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "getline.h"

/*
сравнивает выходной файл и заготовленный результат

@param f [in] - файл со вхдными данными
@param string [in] - тестовая строка
@param n [in,out] - размер текста
@param buff [in] - строка, в которой находится текст
@param flag [out] - результат

@return возвращает 0 если все верно, иначе -1
*/
int checkgetline(char *string, FILE *f, size_t *n, char **buff)
{
    int flag = 0;
    my_getline(buff, n, f);
    if (strcmp(string, *buff) != 0)
    {
        flag = -1;
        puts(string);
        puts(*buff);
    }
    return flag;
}

/*
функция задает строки и открывает файлы

@param flag [out] - результат

@return возвращает 0 если все верно, иначе 1
*/
int testgetline()
{
    char line1[1000] = "No doubt that learning languages takes up a lot of time.\n";
    char line2[1000] = "No doubt that learning languages takes up a lot of time.\n"
                       "That is why some people think that it would be better to\n";
    char line3[1000] = "No doubt that learning languages takes up a lot of time.\n"
                       "That is why some people think that it would be better to\n"
                       "have only one language on our planet. But will it be\n";
    char line4[1000] = "No doubt that learning languages takes up a lot of time.\n"
                      "That is why some people think that it would be better to\n"
                      "have only one language on our planet. But will it be\n"
                      "really beneficial for mankind?\n";

    FILE *f1_in = fopen("in_1.txt", "r+");
    char *buff = calloc(1000, sizeof(char));
    size_t n = 0;

    int flag1 = checkgetline(line1, f1_in, &n, &buff);
    int flag2 = checkgetline(line2, f1_in, &n, &buff);
    int flag3 = checkgetline(line3, f1_in, &n, &buff);
    int flag4 = checkgetline(line4, f1_in, &n, &buff);

    fclose(f1_in);
    return flag1 || flag2 || flag3 || flag4;
}