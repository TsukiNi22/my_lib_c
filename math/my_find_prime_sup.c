/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** Find the first prime above the given integer
*/

#include <math.h>

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (nb < 2)
        return 2;
    for (; !my_is_prime(i); i++);
    return i;
}
