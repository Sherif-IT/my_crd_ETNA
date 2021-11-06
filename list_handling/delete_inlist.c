/*
** ETNA PROJECT, 29/03/2021 by feuvra_v
** delete_inlist
** File description:
**      functions about deleting elements from main list
*/

#include "../include/my.h"

/*
    General deletion functions
    Will take care of choosing which direction to go in
    Deletion if list is present on target is handled seperately
    List position is updated through pointer up to main loop in my_crd.c
*/

int delete_forward(list_t **list, unsigned int key)
{
    list_t *curr = *list;

    if (!curr)
        return (0);
    curr = curr->next;
    while (curr) {
        if (curr->key == key) {
            *list = curr->prev;
            (*list)->next = curr->next;
            if ((*list)->next)
                (*list)->next->prev = *list;
            display_data(curr->data);
            free(curr);
            return (1);
        }
        curr = curr->next;
    }
    return (0);
}

int delete_backward(list_t **list, int unsigned key)
{
    list_t *curr = *list;

    if (!curr)
        return (0);
    curr = curr->prev;
    while (curr) {
        if (curr->key == key) {
            *list = curr->next;
            (*list)->prev = curr->prev;
            if ((*list)->prev)
                (*list)->prev->next = *list;
            display_data(curr->data);
            free(curr);
            return (1);
        }
        curr = curr->prev;
    }
    return (0);
}

void found_target_del(list_t **list, list_t *curr)
{
    display_data(curr->data);
    *list = (curr->prev ? curr->prev : curr->next);
    free(curr);
}

void delete_current(list_t **list)
{
    list_t *tmp;

    tmp = *list;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    *list = (*list)->next ? (*list)->next : (*list)->prev;
    display_data(tmp->data);
    free(tmp);
}

void delete_hub(list_t **list, unsigned int target)
{
    long dir;

    if (list && *list) {
        dir = (*list)->key - target;
        if (dir == 0) {
            delete_current(list);
            return;
        }
        if (dir > 0) {
            if (delete_backward(list, target))
                return;
        }
        else {
            if (delete_forward(list, target))
                return;
        }
    }
    my_putstr("-1\n");
}