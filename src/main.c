/*
** EPITECH PROJECT, 2017
** main
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

int read_file(char *file_path, char ***matrix_str, int *nb_column, int *nb_row)
{
	int file;
	long ret;
	struct stat size;
	stat(file_path, &size);
	long s = size.st_size;
	char *buff = malloc(sizeof(char) * (s + 1));

	file = open(file_path, O_RDONLY);
	ret = read(file, buff, s);
	buff[ret] = '\0';
	*matrix_str = BSQ_tab(buff, nb_column, nb_row);
	if(file == -1)
		return -1;
	close(file);
	free(buff);
	return 0;
}

int main(int argc, char **argv)
{
	char **matrix_str;
	int **matrix;
	point_t max_point = {.x = -1, .y = -1};
	point_t matrix_size;

	if(argc > 2)
		return 84;
	read_file(argv[1], &matrix_str, &matrix_size.x, &matrix_size.y);
	matrix = tab_atoi(matrix_str, matrix_size.x, matrix_size.y);
	inverse_minesweeper(matrix, matrix_str, &max_point, &matrix_size);
	if(max_point.x != -1)
		draw_square(matrix_str, &max_point
			, matrix[max_point.y][max_point.x]);
	display_tab(matrix_str, matrix_size.x, matrix_size.y);
	return 0;
}
