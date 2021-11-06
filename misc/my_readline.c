/*
** ETNA PROJECT, 02/04/2021 by feuvra_v
** my_readline
** File description:
**      readline provided by ETNA
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_readline(void)
{
    size_t n = 0;
    char *ret = NULL;
    ssize_t result = getline(&ret, &n, stdin);

    if (result <= 0) {
        free(ret);
        return NULL;
    }
    if (ret[result - 1] == '\n') {
        ret[result - 1] = '\0';
    }
    return ret;
}
