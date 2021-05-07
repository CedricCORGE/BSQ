/*
** EPITECH PROJECT, 2020
** find_biggest_square.c
** File description:
** find the biggest square in a map
*/

#include "my.h"
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int line = 0;
    int i = row;
    int j = col;
    int k = 0;

    while (line < square_size && map[i][j] == '.') {
        for (k = 0; k < square_size && map[i][j] == '.'; k++)
            j++;
        if (k != square_size)
            return (0);
        j = col;
        i++;
        line++;
    }
    if (line == square_size) {
        return (1);
    } else {
        return (0);
    }
}

int is_square(char **map, int i, int j, int nb_rows)
{
    int indic = 0;
    int counter = 0;

    nb_rows = nb_rows - i;
    while (map[i][j] == '.' && (map[i][j] != '\n' || map[i][j] != '\0') && \
counter < nb_rows) {
        counter++;
        j++;
    }
    j = j - counter;
    while (indic != 1) {
        indic = is_square_of_size(map, i, j, counter);
        counter--;
    }
    if (map[i][j] == '.')
        counter++;
    return (counter);
}

int skip_obstacle(char **map, int i, int j)
{
    int indic = 0;

    while (map[i][j] == 'o') {
        j++;
        indic++;
    }
    if (indic != 0)
        j--;
    return (j);
}

int skip_full_obstacle_row(char **map, int i, int j, int nb_cols)
{
    while (map[i][j] == 'o') {
        j++;
        if (j == nb_cols) {
            i++;
            j = 0;
        }
    }
    return (i);
}

void find_biggest_square(char **map, int nb_rows, int nb_cols)
{
    position *coordo = malloc(sizeof(position));

    for (int i = 0, j = 0; map[i][j] != '\0'; j++) {
        if (j == nb_cols) {
            i++;
            j = 0;
        }
        if (j == 0)
            i = skip_full_obstacle_row(map, i, j, nb_cols);
        j = skip_obstacle(map, i, j);
        coordo->pos_x = j;
        coordo->pos_y = i;
        coordo->size = is_square(map, i, j, nb_rows);
        if (coordo->size_save < coordo->size) {
            coordo->size_save = coordo->size;
            coordo->pos_x_save = coordo->pos_x;
            coordo->pos_y_save = coordo->pos_y;
        }
        coordo->size = 0;
    }
    display_final_result(map, coordo, nb_rows, nb_cols);
}