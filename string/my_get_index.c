/*
** EPITECH PROJECT, 2025
** my_get_index.c
** File description:
** Get the index of the char in the given string
*/

#include "error.h"

int my_get_index(char const *str, char const c)
{
    if (!str)
        return err_prog(PTR_ERR, "In: my_get_index", -2);
    for (int i = 0; i[str]; i++) {
        if (i[str] == c)
            return i;
    }
    return -1;
}
