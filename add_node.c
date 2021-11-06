/*
** ETNA PROJECT, 2021 
** my_crd
** File description:
** add a node so that the list is still in ascending order
*/

#include "my.h"

static void add_nextisnull(list_t **list, unsigned int target, 
unsigned int value)
{
    list_t *tmp = malloc(sizeof(list_t));

    if (tmp) {
        tmp->key = target;
        tmp->data = value;
        tmp->next = NULL;
        tmp->prev = *list;
        (*list)->next = tmp;
        display_data(target);
    }
}

static void add_previsnull(list_t **list, unsigned int target, 
unsigned int value)
{
    list_t *tmp = malloc(sizeof(list_t));

    if (tmp) {
        tmp->key = target;
        tmp->data = value;
        tmp->next = *list;
        tmp->prev = NULL;
        (*list)->prev = tmp;
        display_data(target);
    }
}

static void insert_next(list_t **list, unsigned int target, 
unsigned int value, list_t *current)
{
    list_t *tmp = malloc(sizeof(list_t));

    if (!tmp)
        return;
    *list = current;
    current = current->next;
    tmp->data = value;
    tmp->key = target;
    tmp->next = (*list)->next;
    (*list)->next = tmp;
    tmp->prev = (*list);
    (*list) = current;
    (*list)->prev = tmp;
    display_data(target);
}

static void add_forward(list_t **list, unsigned int target, unsigned int value)
{
    list_t *current = *list;

    while (current->next) {
        if (current->key == target) {
            *list = current;
            (*list)->data = value;
            display_data(target);
            return;
        }
        if (target > current->key && target < current->next->key) {
            insert_next(list, target, value, current);
            return;
        }
        current = current->next;
    }
    *list = current;
    add_nextisnull(list, target, value);

}

static void insert_prev(list_t **list, unsigned int target, 
unsigned int value, list_t *current)
{
    list_t *tmp = malloc(sizeof(list_t));

    if (!tmp)
        return;
    *list = current;
    current = current -> prev;
    tmp->data = value;
    tmp->key = target;
    tmp->prev = (*list)->prev;
    (*list)->prev = tmp;
    tmp->next = (*list);
    *list = current;
    (*list)->next = tmp;
    display_data(target);
}

static void add_backward(list_t **list, unsigned int target, 
unsigned int value)
{
    list_t *current = *list;

    while (current->prev) {
        if (current->key == target) {
            *list = current;
            (*list)->data = value;
            display_data(target);
            return;
        }
        if (target < current->key && target > current->prev->key) {
            insert_prev(list, target, value, current);
            return;
        }
        current = current->prev;
    }
    *list = current;
    add_previsnull(list, target, value);
}

void add_node(list_t **list, unsigned int target, unsigned int value)
{
    long dir;

    if (list && !(*list)) {
        *list = push_front_doublist(*list, target, value);
        display_data(target);
        return;
    }
    if (list && *list) {
        dir = (*list)->key - target;
        if (dir == 0) {
            (*list)->data = value;
            display_data(target);
            return;
        }
        if (dir > 0)
            add_backward(list, target, value);
        else
            add_forward(list, target, value);
    }
}
