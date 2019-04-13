//
// Created by Margo on 16.12.2018.
//

#include "struct.h"

int read_struct(t_city **list, FILE *f, FILE *fo)
{
    int flag = 0;
    char *buff = malloc(300 * sizeof(char));
    while (!feof(f))
    {
        fgets(buff, 300, f);
        t_city *node = malloc(sizeof(t_city));
        int i = 0, count = 0, j = 0, val = 0;
        char *s = malloc(100 * sizeof(char));
        while (buff[i])
        {
            s[j] = buff[i];
            if (buff[i] == ' ')
            {
                s[j] = '\0';
                switch (count)
                {
                    case 0:
                        strcpy(node->name, s);
                        count++;
                        j = -1;
                        break;
                    case 1:
                        strcpy(node->region, s);
                        count++;
                        j = -1;
                        break;
                    case 2:
                        strcpy(node->district, s);
                        count++;
                        j = -1;
                        break;
                    case 3:
                        val = atoi(s);
                        node->population = val;
                        count++;
                        j = -1;
                        break;
                }
            }
            i++;
            j++;
        }
        s[j] = '\0';
        val = atoi(s);
        node->year_of_foundation = val;
        push_t(list, node);
        free(s);
    }
    free(buff);
    return flag;
}