#include <stdio.h>
#include "struct.h"
#include "read_list.h"
#include "popend.h"
#include "list_funcs.h"
#include "popfront.h"
#include "append.h"
#include "insert_sort.h"
#include "menu.h"

/*
Программа выполняет разные действия в зависимости от ключей в командной строке.
Ключ pb - вывести элемент из конца списка.
Ключ pf - вывести элемент из начала списка.
Ключ ap - соединить два списка (в этом случае необходимо ввести еще одно имя файла).
Ключ is - выполняется сортировка списка по возрастанию.
Ключ st - выполняется специальное задание.
*/

int main(int argc, char **argv)
{
    if (argc <= 3)
    {
        puts("No arguments!\n");
    }
    else
    {
        FILE *f = fopen(argv[2], "r+");
        FILE *fo = fopen(argv[3], "w+");

        if (fo && f && argv[1])
        {
            menu(argv[1], argv[4], f, fo);
        }
        else
        {
            puts("Error in opening file!\n");
        }

        fclose(f);
        fclose(fo);
    }

    return 0;
}