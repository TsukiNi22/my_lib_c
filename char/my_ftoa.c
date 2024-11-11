/*
** EPITECH PROJECT, 2024
** my_ftoa.c
** File description:
** Return the string from a float
*/

#include "math.h"
#include "char.h"
#include "write.h"
#include "memory.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int my_strlen_local(char *str)
{
    int len = 0;

    ERR_D(PTR_ERR, "In: my_ftoa > my_strlen_local", KO, (!str));
    for (; str[len] != '\0'; len++);
    free(str);
    return len;
}

static char *my_strcat_local(char *dest, char *src)
{
    int len;
    int i = 0;

    ERR_DN(PTR_ERR, "In: my_ftoa > my_strcat_local", (!dest || !src));
    len = my_strlen(dest);
    ERR_DN(UNDEF_ERR, "In: my_ftoa > my_strcat_local", (len < 0));
    for (; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    free(src);
    return dest;
}

static int get_d_integer(long double nbr, long double *nbr_already,
    int *depth, char **str)
{
    long long cast;
    int signe;

    ERR_D(PTR_ERR, "In: >d_integer", false, (!nbr_already || !depth || !str));
    nbr -= *nbr_already;
    signe = (nbr < 0);
    nbr *= 1 - 2 * (signe == 1 && *depth != 0);
    for (; nbr > LLONG_MAX; nbr /= 10)
        *nbr_already *= 10;
    cast = (long long) nbr;
    *str = my_realloc(*str, my_strlen_local(my_itoa(cast)),
    my_strlen(*str), sizeof(char));
    ERR_D(UNDEF_ERR, "In: my_ftoa > get_d_integer", false, (!(*str)));
    my_strcat_local(*str, my_itoa(cast));
    *nbr_already += cast * (1 - 2 * (signe == 1));
    (*depth)++;
    return (nbr < LLONG_MAX);
}

static int get_d_decimal(long double nbr, long double *nbr_already,
    int *depth, char **str)
{
    long long ll_cast = 0;
    long double d_cast = 0;
    int signe = (nbr < 0);
    char *tmp;

    ERR_D(PTR_ERR, "In: >d_decimal", false, (!nbr_already || !depth || !str));
    nbr = (nbr - *nbr_already * (1 - 2 * signe)) * (1 - 2 * signe);
    if ((long long) (nbr * my_pow(10, my_log(LLONG_MAX, 10) - 1)) == 0)
        return true;
    for (int i = 0; nbr * 10 < LLONG_MAX && i < my_log(LLONG_MAX, 10) * 2; i++)
        nbr *= 10;
    ll_cast = (long long) nbr;
    d_cast = (long double) ll_cast;
    *str = my_realloc(*str, my_strlen_local(my_itoa(ll_cast)),
    my_strlen(*str), sizeof(char));
    my_strcat_local(*str, my_itoa(ll_cast));
    for (; d_cast > 1; d_cast /= 10);
    *nbr_already += d_cast * (1 - 2 * (signe == 1));
    (*depth)++;
    return (ll_cast == 0 || *depth >= 10);
}

static int clear_char(char *str)
{
    ERR_D(PTR_ERR, "In: my_ftoa > clear_char", KO, (!str));
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '.')
            str[i] = '0';
    }
    return OK;
}

static int set_dot(char *str)
{
    int len;

    ERR_D(PTR_ERR, "In: my_ftoa > set_dot", KO, (!str));
    len = my_strlen(str);
    ERR_D(UNDEF_ERR, "In: my_ftoa > set_dot", KO, (len < 0));
    str[len] = '.';
    str[len + 1] = '\0';
    return OK;
}

char *my_ftoa(long double nbr)
{
    char *str = my_malloc(1, sizeof(char));
    long double nbr_already = 0;
    int depth = 0;
    int size;

    ERR_DN(UNDEF_ERR, "In: my_ftoa 1", (!str));
    while (get_d_integer(nbr, &nbr_already, &depth, &str) == 0);
    set_dot(str);
    if (depth < 3) {
        for (depth = 0; get_d_decimal(nbr, &nbr_already, &depth, &str) == 0;);
    }
    if (depth >= 3) {
        size =my_strlen(str);
        str = my_realloc(str, 6, size, sizeof(char));
        ERR_DN(UNDEF_ERR, "In: my_ftoa 2", (!str));
        for (int i = 0; i < 6; i++)
            str[size + i] = '0';
    }
    ERR_DN(UNDEF_ERR, "In: my_ftoa 3", (clear_char(str) == KO));
    return str;
}
