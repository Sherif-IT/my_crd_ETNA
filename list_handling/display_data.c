/*
** ETNA PROJECT, 02/04/2021 by feuvra_v
** display_data
** File description:
**      display given number and return to line
*/

#include "../include/my.h"


void my_putchar(char c)
{
    write(1,&c,1);
}

void my_putstr(char *str)
{
    while (*str) {
        write (1, str, 1);
        str++;
    }
}

void my_putnbr(unsigned int n)
{
    int div = 1000000000;
    int to_print;

    while ((n / div) == 0 && div > 1)
        div = div / 10;
    while (div > 0) {
        to_print = n / div;
        n = n % div;
        div = div / 10;
        my_putchar(to_print + 48);
    }
}

void display_data(int data)
{
    my_putnbr(data);
    my_putchar('\n');
}