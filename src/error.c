/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** error handling
*/

#include "my.h"

int check_valid_characters(char **map, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;

    while (i < nb_rows - 1) {
        while (j < nb_cols && (map[i][j] == '.' || map[i][j] == 'o' \
|| map[i][j] == '\0' || map[i][j] == '\n')) {
            j++;
        }
        if (j != nb_cols) {
            my_puterror("invalid characters in the map\n");
            return (-1);
        }
        j = 0;
        i++;
    }
    return (0);
}

int check_nb_cols(char **map, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;

    while (i < nb_rows - 1) {
        while (map[i][j] != '\n' && map[i][j] != '\0') {
            j++;
        }
        if (j != nb_cols) {
            my_puterror("The map need to have the same length for each row\n");
            return (-1);
        }
        j = 0;
        i++;
    }
    return (0);
}

int check_nb_rows(int nb_rows)
{
    int i = 0;

    while (i < nb_rows - 1) {
        i++;
    }
    if (i == 0) {
        my_puterror("The program need at least one row for work\n");
        return (-1);
    }
    return (0);
}