#ifndef LAB_10_STRUCT_H
#define LAB_10_STRUCT_H

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct node_val
{
    int data;
    struct node_val *next;
}values_i;

typedef struct node_valc
{
    char data;
    struct node_valc *next;
}values_c;

#endif //LAB_10_STRUCT_H
