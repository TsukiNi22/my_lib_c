/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** Allocate memory and copy an array in
*/

#include "string.h"
#include "memory.h"
#include "define.h"
#include "error.h"

char *my_strdup(char const *src)
{
    char *str = NULL;
    int len = 0;

    if (!src)
        return err_prog_n(PTR_ERR, "In: my_strdup");
    len = my_strlen(src);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: my_strdup 1");
    if (my_malloc_c(&str, my_strlen(src) + 1) == KO)
        return err_prog_n(MALLOC_ERR, "In: my_strdup");
    if (!my_strcpy(str, src))
        return err_prog_n(UNDEF_ERR, "In: my_strdup 2");
    return str;
}
