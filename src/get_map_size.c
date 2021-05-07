/*
** EPITECH PROJECT, 2020
** get_nbr_rows.c
** File description:
** get the number of rows and cols of the map
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

int get_nbr_rows(const char *pathfile)
{
    char *buffer;
    int counter = 0;
    int k = 0;

    buffer = load_file_in_mem(pathfile);
    if (buffer == NULL)
        return (-1);
    while (buffer[k] != '\n' && buffer[k] != '\0')
        k++;
    k++;
    for (k = k; buffer[k] != '\0'; k++)
        if (buffer[k] == '\n')
            counter++;
    free(buffer);
    return (counter + 1);
}

int get_nbr_cols(const char *pathfile)
{
    char *buffer;
    int k = 0;
    int counter = 0;

    buffer = load_file_in_mem(pathfile);
    if (buffer == NULL)
        return (-1);
    while (buffer[k] != '\n' && buffer[k] != '\0')
        k++;
    k++;
    for (k = k; buffer[k] != '\n' && buffer[k] != '\0'; k++)
        counter++;
    free(buffer);
    return (counter);
}