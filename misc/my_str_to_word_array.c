/*
** ETNA PROJECT, 18/03/2021 by feuvra_v
** my_str_to_word_array
** File description:
**      Parse string into word, put each word in seperate string, return array
*/

#include <stdlib.h>

int is_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int count_words(const char *str)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        if (is_alphanum(str[i])) {
            while (is_alphanum(str[i]) && str[i])
                i = i + 1;
            count = count + 1;
        }
        if (str[i])
            i = i + 1;
    }
    return (count);
}

int get_word_len(const char *str)
{
    int i = 0;

    while (is_alphanum(str[i]))
        i = i + 1;
    return (i);
}

char **alloc_array(char **array, const char *str, int nb_words)
{
    int i = 0;
    int pos_array = 0;
  
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (!array)
        return (NULL);
    while (str[i]) {
        if (is_alphanum(str[i])) {
            array[pos_array] = malloc(get_word_len(&str[i]) + 1);
            if (!array[pos_array])
                return (NULL);
            i = i + get_word_len(&str[i]) - 1;
            pos_array = pos_array + 1;
        }
        if (str[i])
            i = i + 1;
    }
    array[pos_array] = NULL;
    return (array);
}

char **my_str_to_word_array(const char *str)
{
    char **array = NULL;
    int pos_str = 0;
    int pos_array = 0;
    int pos_word;

    array = alloc_array(array, str, count_words(str));
    if (!array)
        return (NULL);
    while (str[pos_str]) {
        pos_word = 0;
        if (is_alphanum(str[pos_str])) {
            while (is_alphanum(str[pos_str]))
                array[pos_array][pos_word++] = str[pos_str++];
            array[pos_array][pos_word] = 0;
            pos_array = pos_array + 1;
        }
        pos_str = str[pos_str] ? pos_str + 1 : pos_str;
    }
    return (array);
}
