/*
** ETNA PROJECT, 29/03/2021 by feuvra_v
** basic_creat_list
** File description:
**      test linked list generation tool
*/

#include "../include/my.h"

list_t *init_list(unsigned int key, unsigned int value)
{
    list_t *list = malloc(sizeof(list_t));

    if (!list)
        return (NULL);
    list->key = key;
    list->data = value;
    list->prev = NULL;
    list->next = NULL;
    return (list);
}

list_t *push_back_doublist(list_t *list, unsigned int key, unsigned int val)
{
    list_t *new = malloc(sizeof(list_t));

    if (!new)
        return (NULL);
    new->data = val;
    new->key = key;
    new->next = NULL;
    new->prev = NULL;
    if (!list)
        return (new);
    while (list->next)
        list = list->next;
    new->prev = list;
    list->next = new;
    return (new);
}

list_t *push_front_doublist(list_t *list, unsigned int key, unsigned int val)
{
    list_t *new = malloc(sizeof(list_t));

    if (!new)
        return (NULL);
    new->data = val;
    new->key = key;
    new->next = list;
    new->prev = NULL;
    return (new);
}

void free_list(list_t *list)
{
    list_t *tmp = list->next;
    list_t *mid = list;

    list = list->next;
    while (tmp) {
        list = list->next;
        free(tmp);
        tmp = list;
    }
    list = mid;
    while (mid) {
        list = list->prev;
        free(mid);
        mid = list;
    }
}