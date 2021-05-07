/*
** EPITECH PROJECT, 2020
** bsq.h
** File description:
** header for bsq project
*/

#ifndef BSQ_H_
#define BSQ_H_

typedef struct coordo position;

struct coordo
{
    int pos_x_save;
    int pos_y_save;
    int size_save;
    int pos_x;
    int pos_y;
    int size;
};

int is_square(char **map, int i, int j, int nb_rows);

int is_square_of_size(char **map, int row, int col, int square_size);

void find_biggest_square(char **map, int nb_rows, int nb_cols);

int get_nbr_rows(const char *pathfile);

int get_nbr_cols(const char *pathfile);

int full_obstacle_map(char **map, int nb_rows, int nb_cols);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

void display_final_result(char **map, position *coordo, int nb_rows, \
int nb_cols);

char *load_file_in_mem(char const *filepath);

void mem_free_2d_array(char **arr, int nb_rows);

int check_nb_rows(int nb_rows);

int check_nb_cols(char **map, int nb_rows, int nb_cols);

int check_valid_characters(char **map, int nb_rows, int nb_cols);

#endif /* !BSQ_H_ */
