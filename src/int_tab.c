/*
** EPITECH PROJECT, 2017
** int_tab
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int convert_tab_char(char c)
{
	switch (c) {
		case '.':
			return 1;
		default:
			return 0;
	}
}

int *convert_values(int **dest_tab, char **src_tab
		, int row_index, int nb_column)
{
	int y = 0;
	int nb_column_to_process;

	if (row_index == 0)
		nb_column_to_process = nb_column;
	else
		nb_column_to_process = 1;

	for(; y < nb_column_to_process; y++) {
			dest_tab[row_index][y] =
		convert_tab_char(src_tab[row_index][y]);
	}
	return dest_tab[row_index];
}

int **tab_atoi(char **tab_char, int nb_column, int nb_row)
{
	int **tab = malloc(sizeof(int *) * nb_row);
	int i = 0;

	for(i = 0; i < nb_row; i++) {
		tab[i] = malloc(nb_column * sizeof(int));
		tab[i] = convert_values(tab, tab_char, i, nb_column);
	}
	return(tab);
}

void display_int_tab(int **tab, point_t *matrix_size)
{
	for(int i = 0; i < matrix_size->y; i++) {
		for(int j = 0; j < matrix_size->x; j++) {
			my_putchar(tab[i][j] + '0');
		}
		my_putchar('\n');
	}
}
