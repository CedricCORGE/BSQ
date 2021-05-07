/*
** EPITECH PROJECT, 2020
** mem_alloc_2d_array.c
** File description:
** return adress of new memory zone
*/

#include <stdlib.h>
#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **arr;

    arr = malloc(sizeof(char *) * nb_rows);
    while (i < nb_rows) {
        arr[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    return (arr);
}
