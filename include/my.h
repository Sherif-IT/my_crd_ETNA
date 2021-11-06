/*
** ETNA PROJECT, 29/03/2021 by feuvra_v
** my
** File description:
**      general header for my_crd
*/

#include <stdlib.h>
#include <unistd.h>

typedef struct linked_list {
    unsigned int key;
    unsigned int data;
    struct linked_list *next;
    struct linked_list *prev;
} list_t;

char *my_readline(void);
void my_putchar(char c);
void my_putnbr(unsigned int n);
void my_putstr(char *str);
unsigned int my_getnbr(const char *str);
void display_data(int data);
char **my_str_to_word_array(const char *str);
list_t *push_front_doublist(list_t *list, unsigned int key, unsigned int val);
list_t *push_back_doublist(list_t *list, unsigned int key, unsigned int val);
list_t *init_list(unsigned int key, unsigned int value);
void delete_hub(list_t **list, unsigned int target);
int delete_backward(list_t **list, unsigned int key);
int delete_forward(list_t **list, unsigned int key);
list_t *find_node(list_t *list, unsigned int target);
void my_print_list(list_t *list);
void my_print_revlist(list_t *list);
void lookup_node(list_t **list, unsigned int target);
void add_node(list_t **list, unsigned int target, unsigned int value);
void free_list(list_t *list);