//
// Created by Margo on 17.12.2018.
//

#include "add_elem.h"
#include "struct.h"
#include <malloc.h>
#include "push_marks.h"
#include "push_node.h"
#include "print.h"

void add_elem(t_stud **list)
{
    char *s = malloc(100 * sizeof(char));
    int age = 0, num_marks, mark = 0;
    t_marks *list_m = NULL;
    t_stud *node = malloc(sizeof(t_stud));
    printf("������ 䠬���� ��㤥��:\n");
    scanf("%s", s);
    strcpy(node->name, s);
    printf("������ ������ ��㤥��: \n");
    scanf("%d", &age);
    node->age = age;
    printf("������ ������⢮ �業��: \n");
    scanf("%d", &num_marks);
    for (int i = 0; i < num_marks; i++)
    {
        printf("������ �業��: \n");
        scanf("%d", &mark);
        push_marks(&list_m, mark);
    }
    node->list_marks = list_m;
    push_t(list, node);
}