/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** Error handling
*/

#include "write.h"
#include "define.h"
#include "error.h"

void err_custom_v(char *error_info)
{
    if (!CUSTOM_PUT_ERROR)
        return;
    print_error_info(error_info);
}

void *err_custom_n(char *error_info)
{
    if (!CUSTOM_PUT_ERROR)
        return NULL;
    print_error_info(error_info);
    return NULL;
}

int err_custom(char *error_info, int to_return)
{
    if (!CUSTOM_PUT_ERROR)
        return to_return;
    print_error_info(error_info);
    return to_return;
}