/*
** EPITECH PROJECT, 2025
** get_fullpath.c
** File description:
** Cat tow system path
*/

#include "string.h"
#include "memory.h"
#include "define.h"
#include "error.h"

char *get_full_path(char const *cr_path, char const *file)
{
    char *path = NULL;
    int len[3] = {0};

    if (!cr_path || !file)
        return err_prog_n(PTR_ERR, "In: get_full_path");
    len[0] = my_strlen(cr_path);
    len[1] = my_strlen(file);
    if (len[0] < 0 || len[1] < 0)
        return err_prog_n(UNDEF_ERR, "In: get_full_path 1");
    if (my_malloc_c(&path, len[0] + len[1] + 2) == KO)
        return err_prog_n(UNDEF_ERR, "In: get_full_path 2");
    if (!my_strcat(path, cr_path))
        return err_prog_n(UNDEF_ERR, "In: get_full_path 3");
    len[2] = my_strlen(path);
    if (len[2] < 0)
        return err_prog_n(UNDEF_ERR, "In: get_full_path 4");
    if ((path[len[2] - 1] != '/' && !my_strcat(path, "/\0"))
        || !my_strcat(path, file))
        return err_prog_n(UNDEF_ERR, "In: get_full_path 5");
    return path;
}
