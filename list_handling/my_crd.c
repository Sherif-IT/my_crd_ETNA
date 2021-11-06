/*
** ETNA PROJECT, 31/03/2021 by feuvra_v
** my_crd
** File description:
**      main for my crd
*/

#include "../include/my.h"

static int is_num(char c)
{
    return ((c <= '9' && c >= '0') ? 1 : 0);
}

static void free_array(char **array)
{
    int i = 0;

    while (array[i]) {
        free(array[i]);
        i = i + 1;
    }
    free(array);
}

/*
    Main loop
    Takes care of checking flags, if values exist
    Will not print anything if passed file is empty
    Empty lines will print -1
*/

void loop_onstdin(list_t *list, char *line, char **array, int value_exists)
{
    while (line) {
        if (line[0]) {
            array = my_str_to_word_array(line);
            value_exists = array[1] ? is_num(array[1][0]) : 0;
            if (array[1] && array[1][0] == 'D')
                delete_hub(&list, my_getnbr(array[0]));
            else if (array[1] && value_exists) {
                add_node(&list, my_getnbr(array[0]), my_getnbr(array[1]));
            }
            else if(!array[1])
                lookup_node(&list, my_getnbr(array[0]));
            free_array(array);
        }
        else
            my_putstr("-1\n");
        free(line);
        line = my_readline();
    }
    if (list)
        free_list(list);
}

int main(void)
{
    list_t *list = NULL;
    char *line = NULL;
    char **array = NULL;
    int value_exists = 0;

    line = my_readline();
    loop_onstdin(list, line, array, value_exists);
    return (0);
}
