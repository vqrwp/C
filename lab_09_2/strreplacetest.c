#include "strreplacetest.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "strreplace.h"
#include "getline.h"
#include "sstrcmp.h"

/*
сравнивает выходной файл и заготовленный результат

@param f1 [in] - файл со вхдными данными
@param f2 [in] - тестовый файл
@param serach [in] - первая строка
@param replace [in] - строка, на которую заменяем
@param flag [out] - результат

@return возвращает 0 если все верно, иначе -1
*/
int checkrepl(FILE *f1, FILE *f2, char *serach, char *replace)
{
    int flag = 0;
    while (!feof(f1))
    {
        char *buff1 = calloc(128, sizeof(char)), *buff2 = calloc(128, sizeof(char));
        fgets(buff1, 10000, f1);
        fgets(buff2, 10000, f2);
        buff1 = str_replace(buff1, serach, replace);
        if (my_strcmp(buff1, buff2) != 0)
        {
            flag = 1;
            printf("%s\n", buff1);
            printf("%s\n", buff2);
        }
        free(buff1);
        free(buff2);
    }
    return flag;
}

/*
функция задает строки и открывает файлы

@param flag [out] - результат

@return возвращает 0 если все верно, иначе 1
*/
int teststrreplace()
{
    FILE *f1_in = fopen("in_1.txt", "r+");
    FILE *f2_in = fopen("in_2.txt", "r+");
    FILE *f3_in = fopen("in_3.txt", "r+");

    FILE *f1_out = fopen("out_1.txt", "r+");
    FILE *f2_out = fopen("out_2.txt", "r+");
    FILE *f3_out = fopen("out_3.txt", "r+");

    int flag1 = checkrepl(f1_in, f1_out, "lang", "gnal"),
            flag2 = checkrepl(f2_in, f2_out, "animal", "-------"),
                    flag3 = checkrepl(f3_in, f3_out, "aa a", "===");

    fclose(f2_in);
    fclose(f1_in);
    fclose(f3_in);

    fclose(f2_out);
    fclose(f1_out);
    fclose(f3_out);
    return flag1 || flag2 || flag3;
}