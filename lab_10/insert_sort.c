#include "insert_sort.h"
#include <stdio.h>
#include "popend.h"
#include "list_funcs.h"
#include "push.h"
#include <malloc.h>
#include "append.h"

/*
Получает список и упорядочивает его по возрастанию, используя функцию sorted_insert.

@param head [in] - входной список
@param comparator [in] - функция сравнения
@param newroot [out] - упорядоченный список

@return упорядоченный список
*/
node_t* sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_root = NULL;
    if (head != NULL)
    {
        void *first = pop_back(&head);
        int flag = 0;
        push(&new_root, first);
        if (head == NULL)
        {
           flag = 1;
        }
        while (head->next != NULL)
        {
            node_t *next = head;
            sorted_insert(&new_root, next, comparator);
            head = head->next;
        }
        if (flag != 1)
        {
            node_t *next = head;
            sorted_insert(&new_root, next, comparator);
        }
    }
    return new_root;
}

/*
Функция сравнения int

@param p [in] - первое значение
@param q [in] - второе значение
@return возвращает разницу между введенными значениями
*/
int comparator_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

/*
Функция сравнения char

@param p [in] - первое значение
@param q [in] - второе значение
@return возвращает разницу между введенными значениями
*/
int comparator_char(const void *p, const void *q)
{
    const char *a = p;
    const char *b = q;
    return *a - *b;
}

/*
Функция сравнения float

@param p [in] - первое значение
@param q [in] - второе значение
@return возвращает разницу между введенными значениями
*/
int comparator_float(const void *p, const void *q)
{
    const float *a = p;
    const float *b = q;
    return (int)(*a - *b);
}

/*
Получает упорядоченный список, и элемент,
который нужно вставить в этот список, чтобы не нарушить его упорядоченности.

@param head [in] - входной список
@param element [in] - элемент, который надо вставить
@param comparator [in] - функция сравнения

@return ничего не возвращает
*/
void sorted_insert(node_t **head, node_t *element,
                   int (*comparator)(const void *, const void *)) {
    node_t *ptr = NULL;
    node_t *tmp = NULL;
    unsigned char flag = 0;
    void *x = element->data;
    if (comparator(element->data, (*head)->data) >= 0) /* вставить перед первым */
    {
        ptr = malloc(sizeof(node_t));
        ptr->data = x;
        ptr->next = (*head);
        *head = ptr;
    }
    else
    {
        tmp = (*head);
        while ((flag == 0) && (tmp->next != NULL))
        {
            if (comparator(tmp->data, tmp->next->data) >= 0 &&
                comparator(element->data, tmp->next->data) > 0)
            {
                flag = 1;
            }
            if (flag != 1)
            {
                tmp = tmp->next;
            }
        }
        if (flag == 0)
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = NULL;
            tmp->next = ptr;
        }
        else
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = tmp->next;
            tmp->next = ptr;
        }
    }
}
