/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Find the first occurence of a sting in a string
*/

#include "char.h"
#include "define.h"
#include "error.h"

char *my_strstr(char *str, char const *to_find)
{
    int len = 0;
    int size = 0;
    int i = 0;

    if (!str || !to_find)
        return err_prog_n(PTR_ERR, "In: my_strstr");
    len = my_strlen(to_find);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: my_strstr");
    for (; size < len && str[i]; i++) {
        if (str[i] == to_find[size])
            size++;
        else
            size = 0;
    }
    if (size >= len)
        return &str[i - len];
    return NULL;
}
