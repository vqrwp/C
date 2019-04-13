#include <stdio.h>
#include "counting_words_in_file.h"

// рассчитать количество вхождений каждого файла
// слова разделены знаками ".", ",", ";"
// fgets для чтения строки
// while (fgets(str, n, f) - обработка str
// variant 2.1

int main(int argc, char **argv) {
    FILE *fi = fopen(argv[1], "r+");
    FILE *fo = fopen(argv[2], "w+");
    int flag = 0;
    num_words *arr = NULL;
    if (fi && fo)
    {
        arr = counting_words(fi, fo);
    }
    else
    {
        printf("Error in opening file!");
        flag = -1;
    }
    fclose(fi);
    fclose(fo);
    return flag;
}