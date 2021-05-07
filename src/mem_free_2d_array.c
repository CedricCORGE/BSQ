/*
** EPITECH PROJECT, 2020
** mem_free_2d_array.c
** File description:
** free 2d array
*/

#include <stdlib.h>

void mem_free_2d_array(char **arr, int nb_rows)
{
    int i = 0;

    while (i < nb_rows) {
        free(arr[i]);
        i++;
    }
    free(arr);
}