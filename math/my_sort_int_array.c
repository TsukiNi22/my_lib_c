/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** Sort an array of int
*/

#include "error.h"

static int raaaa(int *already_sorted, int *changed, int *save_i, int smallest)
{
    if (!already_sorted || !changed || !save_i)
        return err_dispatch(PTR_ERR, "In: sort_int_array 3.1", 0);
    if (*changed != 1)
        already_sorted[*changed * -1] = 1;
    else
        already_sorted[*save_i] = 1;
    return smallest;
}

static int get_smallest(int *array, int size, int *already_sorted)
{
    int first = 1;
    int changed = 0;
    int smallest;
    int save_i;

    if (!already_sorted)
        return err_dispatch(PTR_ERR, "In: sort_int_array 2.1", 0);
    for (int i = 0; i < size; i++) {
        if (first && already_sorted[i] == 0) {
            smallest = array[i];
            changed = i * -1;
            first = 0;
        }
        if (!first && smallest >= array[i] && already_sorted[i] == 0) {
            changed = 1;
            smallest = array[i];
            save_i = i;
        }
    }
    return raaaa(already_sorted, &changed, &save_i, smallest);
}

int my_sort_int_array(int *array, int size)
{
    int sort_array[size];
    int already_sorted[size];

    if (!array)
        return err_dispatch(PTR_ERR, "In: sort_int_array 1", KO);
    if (size < 0)
        return err_dispatch(ARGV_ERR, "In: sort_int_array", KO);
    for (int i = 0; i < size; i++)
        already_sorted[i] = 0;
    for (int i = 0; i < size; i++)
        sort_array[i] = get_smallest(array, size, already_sorted);
    for (int i = 0; i < size; i++)
        array[i] = sort_array[i];
    return 0;
}
