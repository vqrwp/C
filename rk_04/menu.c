//
// Created by Margo on 17.12.2018.
//

#include "menu.h"
#include "print.h"
#include "add_elem.h"
#include "delete_node.h"
#include "free.h"

void menu(t_stud *list)
{
    int menu_choise = 0;
    while (menu_choise == 0)
    {
        printf("Программа обрабатывает односвязный список. Выберите опцию меню, которую вы хотите воспроизвести:\n");
        printf("1. Добавить элемент в конец списка\n");
        printf("2. Удалить элемент из конца списка\n");
        printf("3. Вывести элементы списка на экран\n");
        printf("4. Выход\n");
        printf("Введите номер соответствующего пункта меню:\n");
        scanf("%d", &menu_choise);
        switch (menu_choise)
        {
            case 1:
                add_elem(&list);
                menu_choise = 0;
                break;
            case 2:
                pop_back(&list);
                menu_choise = 0;
                break;
            case 3:
                print_from_head(list, 0);
                printf("\n");
                menu_choise = 0;
                break;
            case 4:
                list = frees(list);
                break;
            default:
                printf("Неверный ввод!\n");
                menu_choise = 0;
                break;
        }
    }
}