/*
** EPITECH PROJECT, 2020
** load_2d_array_from_file.c
** File description:
** load the map
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *map;
    struct stat statbuf;

    if (fd < 0) {
        my_puterror("Can't open the file\n");
        return (NULL);
    }
    if (stat(filepath, &statbuf) == -1)
        return (NULL);
    map = malloc(sizeof(char) * statbuf.st_size + 1);
    if (map == NULL)
        return (NULL);
    if (read(fd, map, statbuf.st_size) == -1)
        return (NULL);
    map[statbuf.st_size] = '\0';
    close(fd);
    return (map);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char *file = load_file_in_mem(filepath);
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);
    int i = 0;
    int j = 0;
    int k = 0;

    if (file == NULL)
        return (NULL);
    while (file[k] != '\n' && file[k] != '\0')
        k++;
    k++;
    for (i = 0; i < nb_rows; i++) {
        while (j < nb_cols + 1) {
            map[i][j] = file[k];
            j++;
            k++;
        }
        j = 0;
    }
    return (map);
}