/*
** EPITECH PROJECT, 2017
** my_h
** File description:
** BSQ
*/

#ifndef _MY_H_
#define _MY_H_

typedef struct point_s point_t;
int line_counter(char *str);
void my_putchar(char);
char *my_putstr(char *str);
int my_atoi(char *str);
int my_strlen_to(char *str, char delimiter);
char *my_linecpy(char *dest,char *src, int *n);
char **BSQ_tab(char *buff, int *nb_column, int *nb_row);
void display_tab(char **tab, int nb_column, int nb_row);
int **tab_atoi(char **tab_char, int nb_column, int nb_row);
void display_int_tab(int **tab, point_t *matrix_size);
int compute_point(point_t *cur_point, int **matrix, char **matrix_str);
void my_putnbr(int nb);
int my_min_ter(int a, int b, int c);
int my_min(int b, int c);
char *my_putnstr(char *str, int size);
char **draw_square(char** matrix, point_t *max_point, int max_point_value);
int my_max(int a, int b);
int set_max_point(point_t *max_point, point_t *cur_point
		, int **matrix, int old_max_value);
point_t *inverse_minesweeper(int **matrix, char** matrix_str
				, point_t *max_point
				, point_t *matrix_size);
char **draw_square(char** matrix, point_t *max_point, int max_point_value);

typedef struct point_s {
	int x;
	int y;
} point_t;

#endif
