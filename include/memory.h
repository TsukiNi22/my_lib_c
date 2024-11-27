/*
** EPITECH PROJECT, 2024
** math.h
** File description:
** Header for all thing who have a link with memory
*/

#pragma once

#ifndef MEMORY
    #define MEMORY

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* include_type */
    #include <stdbool.h> // boolean

//----------------------------------------------------------------//
/* PROTOTYPE */

/* memory_gestion */
//int my_malloc(void *ptr, int size, int type_size); // Error: KO
//int my_calloc(void *ptr, int size, int type_size); // Error: KO
//int my_realloc(void *ptr, int add, int size, int type_size); // Error: KO

/* memory_type_gestion */
int my_malloc_b(bool **ptr, int size); // Error: KO
int my_malloc_c(char **ptr, int size); // Error: KO
int my_malloc_i(int **ptr, int size); // Error: KO
int my_malloc_f(float **ptr, int size); // Error: KO

int my_calloc_b(bool **ptr, int size); // Error: KO
int my_calloc_c(char **ptr, int size); // Error: KO
int my_calloc_i(int **ptr, int size); // Error: KO
int my_calloc_f(float **ptr, int size); // Error: KO

int my_realloc_b(bool **ptr, int add, int size); // Error: KO
int my_realloc_c(char **ptr, int add, int size); // Error: KO
int my_realloc_i(int **ptr, int add, int size); // Error: KO
int my_realloc_f(float **ptr, int add, int size); // Error: KO

/* memory_char */
char *my_strdup(char const *src); // Error: NULL

/* memory_swap */
int my_swap_c(char *a, char *b); // Error: KO
int my_swap_i(int *a, int *b); // Error: KO
int my_swap_f(float *a, float *b); // Error: KO

#endif /* MEMORY */
