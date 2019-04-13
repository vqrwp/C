#ifndef LAB_13_LIST_H
#define LAB_13_LIST_H

#include <stdio.h>
#include <stddef.h>
#define SIZE_ARR 100
#define MAX_SORT_INDX 2
#define MAX_FILTER_INDX 3
#define SUBJ "Physics"
#define OLDEST 40
#define FACULTY "FN"

typedef struct head
{
    struct head *next, *prev;
}head_t;

typedef struct lecturers
{
    char department[SIZE_ARR];
    char lecturer[SIZE_ARR];
    char subject[SIZE_ARR];
    int age;

    head_t sort[MAX_SORT_INDX];
    head_t filter[MAX_FILTER_INDX];
    struct lecturers *next;
}lect_t;



#ifndef container_of
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */

#if 0
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })
#endif

#define container_of(ptr, type, field_name) ( \
    (type *) ((char *) (ptr) - offsetof(type, field_name)))

#endif

/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

#define LIST_HEAD_INIT(name) {&(name), &(name)}

#define LIST_HEAD(name) head_t name = LIST_HEAD_INIT(name)

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
#ifndef CONFIG_DEBUG_LIST
static inline void __list_add(head_t *new, head_t *prev, head_t *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
#else
extern void __list_add(head_t *new,
			      head_t *prev,
			      head_t *next);
#endif

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(head_t *new, head_t *head)
{
    __list_add(new, head, head->next);
}


/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(head_t *new, head_t *head)
{
    __list_add(new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(head_t * prev, head_t * next)
{
    next->prev = prev;
    prev->next = next;
}

/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
#ifndef CONFIG_DEBUG_LIST
static inline void __list_del_entry(head_t *entry)
{
    __list_del(entry->prev, entry->next);
}

static inline void list_del(head_t *entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = NULL;
    entry->prev = NULL;
}
#else
extern void __list_del_entry(head_t *entry);
extern void list_del(head_t *entry);
#endif

/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop cursor.
 * @head:	the head for your list.
 */
#define list_for_each(pos, head) \
	for ((pos) = (head)->next; (pos) != (head); (pos) = (pos)->next)

#endif //LAB_13_LIST_H
