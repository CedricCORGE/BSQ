/*
** EPITECH PROJECT, 2020
** display_final_result.c
** File description:
** display the final result. with the biggest square
*/

#include "my.h"
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void display_final_result(char **map, position *coordo, int nb_rows, \
int nb_cols)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < coordo->size_save; i++) {
        for (j = 0; j < coordo->size_save; j++) {
            map[coordo->pos_y_save][coordo->pos_x_save] = 'x';
            coordo->pos_x_save++;
        }
        coordo->pos_x_save -= j;
        coordo->pos_y_save++;
    }
    for (i = 0; i < nb_rows - 1; i++)
        write(1, map[i], nb_cols + 1);
    free(coordo);
}