/*
** ETNA PROJECT, 31/03/2021 by feuvra_v
** lookup_node
** File description:
**      all functions about looking up a node of given key
*/

#include "../include/my.h"

void lookup_forward(list_t **list, unsigned int target)
{
    list_t *curr = *list;

    curr = curr->next;
    while (curr) {
        if (curr->key == target) {
            display_data(curr->data);
            *list = curr;
            return;
        }
        curr = curr->next;
    }
    my_putstr("-1\n");
}

void lookup_backward(list_t **list, unsigned int target)
{
    list_t *curr = *list;

    curr = curr->prev;
    while (curr) {
        if (curr->key == target) {
            display_data(curr->data);
            *list = curr;
            return;
        }
        curr = curr->prev;
    }
    my_putstr("-1\n");
}

void lookup_node(list_t **list, unsigned int target)
{
    long dir;

    if (list && *list) {
        dir = (*list)->key - target;
        if (dir == 0) {
            display_data((*list)->data);
            return;
        }
        if (dir > 0) {
            lookup_backward(list, target);
            return;
        }
        else {
            lookup_forward(list, target);
            return;
        }
    }
    my_putstr("-1\n");
}