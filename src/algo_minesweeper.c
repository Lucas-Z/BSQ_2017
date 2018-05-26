/*
** EPITECH PROJECT, 2017
** minesweeper
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

point_t *inverse_minesweeper(int **matrix, char** matrix_str
			, point_t *max_point
			, point_t *matrix_size)
{
	point_t cur_point = {.x = 0, .y = 0};
	int max_value = 0;

	while (cur_point.y < matrix_size->y) {
		while (cur_point.x < matrix_size->x) {
			matrix[cur_point.y][cur_point.x]
			= compute_point(&cur_point, matrix, matrix_str);
			max_value = set_max_point(max_point
						, &cur_point
						, matrix, max_value);
			cur_point.x++;
		}
		cur_point.x = 0;
		cur_point.y++;
	}
	return max_point;
}

int set_max_point(point_t *max_point, point_t *cur_point
		, int **matrix, int old_max_value)
{
	int new_value = matrix[cur_point->y][cur_point->x];

	if (my_max(new_value, old_max_value) != old_max_value) {
		max_point->x = cur_point->x;
		max_point->y = cur_point->y;
		return new_value;
	}
	return old_max_value;
}

int compute_point(point_t *cur_point, int **matrix, char **matrix_str)
{
	if (cur_point->y == 0
		|| cur_point->x == 0) {
		return matrix[cur_point->y][cur_point->x];
	} else if(matrix_str[cur_point->y][cur_point->x] == 'o') {
		return 0;
	}
	return my_min_ter(
		matrix[cur_point->y-1][cur_point->x]
		, matrix[cur_point->y - 1][cur_point->x - 1]
		, matrix[cur_point->y][cur_point->x - 1]) + 1;
}

char **draw_square(char** matrix, point_t *max_point, int max_point_value)
{
	int x = 0;
	int y = 0;

	if (matrix == NULL || max_point == NULL) {
		return matrix;
	}
	while (y < max_point_value) {
		while (x < max_point_value) {
			matrix[max_point->y - y][max_point->x - x] = 'x';
			x++;
		}
		x = 0;
		y++;
	}
	return matrix;
}
