#include "counting_words_in_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_struct.h"

num_words *empty(num_words *arr)
{
    for (int i = 0; i < 100; i++)
    {
        arr[i].num = 0;
        arr[i].string = malloc(100 * sizeof(char));
    }
    return arr;
}

num_words *counting_words(FILE *fi, FILE *fo)
{
    char *str = malloc(101 * sizeof(char));
    num_words *arr = malloc(100 * sizeof(num_words));
    arr = empty(arr);
    int n = 100, size_of_arr = 0;
    char *buff = malloc(100 * sizeof(char));
    while (fgets(str, n, fi))
    {
        int i = 0;
        str[strlen(str) - 1] = '\0';
        while (str[i] != '\0')
        {
            int count = 0;
            if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ' ')
            {
                str[i] = ' ';
                i++;
            }
            int k = i;
            while (str[k] != '.' && str[k] != ',' && str[k] != ';' && str[k] != ' '&& str[k] != '\0')
            {
                buff[count] = str[k];
                str[k] = ' ';
                count++;
                k++;
            }
            if (buff[0] != ' ')
            {
                char *ch = strchr(buff, ' ');
                if (ch)
                {
                    *ch = '\0';
                }
                int flag = 0;
                for (int j = 0; j < size_of_arr; j++)
                {
                    if (strcmp(buff, arr[j].string) == 0)
                    {
                        flag = 1;
                        arr[j].num++;
                    }
                }
                if (flag == 0)
                {
                    strcpy(arr[size_of_arr].string, buff);
                    arr[size_of_arr].num++;
                    size_of_arr++;
                }
                for (int j = 0; j < count; j++)
                {
                    buff[j] = ' ';
                }
            }
        }
    }
    print_struct(fo, arr, size_of_arr);
    free(str);
    free(arr);
    free(buff);
    return arr;
}
