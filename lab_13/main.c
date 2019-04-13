#include <stdio.h>
#include "menu.h"

int main(int argc, void **argv)
{
    int flag = 1;
    if (!argv[1])
    {
        printf("Mistake in command line arguments!\n");
        flag = -1;
    }
    else
    {
        FILE *f = fopen(argv[1], "r+");
        FILE *fo = fopen("res.txt", "w+");
        if (!f)
        {
            printf("Error in opening file!\n");
            flag = -1;
        }
        else
        {
            flag = menu(f, fo);
        }
        fclose(f);
        fclose(fo);
    }
    return flag;
}