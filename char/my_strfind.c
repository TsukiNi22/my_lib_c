/*
** EPITECH PROJECT, 2024
** my_strfind.c
** File description:
** Find a char in the given array and retur nthe place
*/

#include "error.h"

int my_strfind(const char *char_array, const char find_char)
{
    int place = 0;

    if (!char_array)
        return err_dispatch(PTR_ERR, "In: strfind", KO * -1);
    for (; char_array[place] && char_array[place] != find_char; place++);
    if (char_array[place] == '\0')
        return -1;
    return place;
}