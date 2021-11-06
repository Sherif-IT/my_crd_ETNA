/*
** ETNA PROJECT, 16/03/2021 by feuvra_v
** my_getnbr
** File description:
**      Parse a number from a string taken as parameter, and return the number
*/

int get_firstnbr(const char *str)
{
    int pos = 0;

    while (str[pos] < '0' || str[pos] > '9') {
        if (str[pos] == '\0')
            return (-1);
        if (str[pos] != '+')
            return (-1);
        pos = pos + 1;
    }
    return (pos);
}

int check_overflow(const char *str, int pos, unsigned int result)
{
    if (result == 429496729) {
        if ((str[pos] - 48) > 5)
            return (0);
    }
    if (str[pos + 1] >= '0' && str[pos + 1] <= '9')
        return (0);
    result = (result * 10) + (str[pos] - 48);
    return (result);
}

int count_minus(const char *str)
{
    int i = 0;
    int m_count = 0;

    while (str[i] && (str[i] == '-' || str[i] == '+')) {
        m_count = str[i] == '-' ? m_count + 1 : m_count;
        i = i + 1;
    }
    if (m_count % 2 == 0)
        return (1);
    return (-1);
}

unsigned int my_getnbr(const char *str)
{
    int first_nb = get_firstnbr(str);
    int pos = first_nb;
    unsigned int result = 0;

    if (first_nb < 0)
        return (0);
    while (str[pos] && pos < (first_nb + 9)) {
        if (str[pos] > '9' || str[pos] < '0')
            return (result);
        result = result * 10 + (str[pos] - 48);
        pos = pos + 1;
    }
    if (str[pos] >= '0' && str[pos] <= '9')
        return (check_overflow(str, pos, result));
    return (result);
}
