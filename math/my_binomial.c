/*
** EPITECH PROJECT, 2024
** my_binomial.c
** File description:
** My binomial
*/

#include "math.h"
#include "error.h"

int my_binomial(float n, float k)
{
    float result = 0.0;

    if (n < k || k < 0)
        return err_prog(ARGV_ERR, "In: my_binomial", KO);
    if (k > 170 || n > 170)
        return err_prog(OVERFLOW, "In: my_binomial", KO);
    if (((long long) n) - n == 0 && ((long long) k) - k == 0)
        result = my_factorial(n) / (my_factorial(k) * my_factorial(n - k));
    else
        result = my_gamma(n) / (my_gamma(k) * my_gamma(n - k));
    return result;
}
