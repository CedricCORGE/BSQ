/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for bsq project
*/

#include "my.h"
#include "bsq.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    int indic = 0;
    int indic2 = 0;
    int indic3 = 0;
    int indic4 = 0;
    int nb_rows = get_nbr_rows(av[1]);
    int nb_cols = get_nbr_cols(av[1]);
    char **map = load_2d_arr_from_file(av[1], nb_rows, nb_cols);

    if (map == NULL || nb_rows == -1 || nb_cols == -1)
        return (84);
    indic2 = check_nb_cols(map, nb_rows, nb_cols);
    indic3 = check_nb_rows(nb_rows);
    indic4 = check_valid_characters(map, nb_rows, nb_cols);
    if (indic2 == -1 || indic3 == -1 || ac != 2 || indic4 == -1)
        return (84);
    indic = full_obstacle_map(map, nb_rows, nb_cols);
    if (indic != 0)
        find_biggest_square(map, nb_rows, nb_cols);
    mem_free_2d_array(map, nb_rows);
    return (0);
}