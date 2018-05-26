/*
** EPITECH PROJECT, 2017
** char_tab
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

char **BSQ_tab(char *buff, int *nb_column, int *nb_row)
{
	char **tab;
	int i = 0;
	int n = 0;
	char nb_lines_str[200];

	*nb_row = my_atoi(my_linecpy(nb_lines_str, buff, &n));
	*nb_column = my_strlen_to(&buff[n],'\n');
	tab = malloc(sizeof(int *) * (*nb_row));



	for (i = 0; i < *nb_row ; i++) {
		tab[i] = malloc(*nb_column * sizeof(int));
		tab[i] = my_linecpy(tab[i], buff, &n);
	}
	return (tab);
}

void display_tab(char **tab, int nb_column, int nb_row)
{
	int i = 0;

	for (; i < nb_row; i++) {
		my_putnstr(tab[i], nb_column);
		my_putchar('\n');
	}
}
