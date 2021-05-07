/*
** EPITECH PROJECT, 2020
** full_obstacle_map.c
** File description:
** check if the map is full obstacles
*/

#include <unistd.h>
#include "my.h"

void display_2d_array(char **map, int nb_rows, int nb_cols)
{
    int i = 0;

    while (i < nb_rows - 1) {
        write(1, map[i], nb_cols + 1);
        i++;
    }
}

int full_obstacle_map(char **map, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;
    int indic = 0;

    while (i < nb_rows) {
        while (j < nb_cols && (map[i][j] == 'o' || \
map[i][j] == '\n' || map[i][j] == '\0')) {
            j++;
        }
        if (j == nb_cols)
            indic++;
        j = 0;
        i++;
    }
    if (indic == nb_rows) {
        display_2d_array(map, nb_rows, nb_cols);
        return (0);
    } else {
        return (1);
    }
}