/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** Write P when the given parameter is greter than 0 or N in oser cases
*/

#include "write.h"
#include "include.h"
#include "error.h"

int my_isneg(int n)
{
    char c = 'P';

    if (n < 0)
        c = 'N';
    if (my_putchar(c) == KO)
        return err_dispatch(WRITE_ERR, "In: isneg", KO);
    return 0;
}
