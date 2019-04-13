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
        printf("�ணࠬ�� ��ࠡ��뢠�� �����吝� ᯨ᮪. �롥�� ���� ����, ������ �� ��� ���ந�����:\n");
        printf("1. �������� ����� � ����� ᯨ᪠\n");
        printf("2. ������� ����� �� ���� ᯨ᪠\n");
        printf("3. �뢥�� ������ ᯨ᪠ �� �࠭\n");
        printf("4. ��室\n");
        printf("������ ����� ᮮ⢥�����饣� �㭪� ����:\n");
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
                printf("������ ����!\n");
                menu_choise = 0;
                break;
        }
    }
}