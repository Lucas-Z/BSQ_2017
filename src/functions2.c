/*
** EPITECH PROJECT, 2017
** function_part2
** File description:
** BSQ
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putnbr(int nb)
{
	if (nb >= 10) {
		my_putnbr(nb/10);
	}
	my_putchar((nb % 10) + '0');
}

char *my_linecpy(char *dest, char *src, int *n)
{
	int i = 0;

	while(src[*n] != '\n') {
		dest[i] = src[*n];
		*n = *n + 1;
		i++;
	}
	dest[i] = '\0';
	*n = *n + 1;
	return(dest);
}

int line_counter(char *str)
{
	int nb_line = 0;

	for(int index = 0; str[index] != '\0'; index++) {
		if(str[index] == '\n')
			nb_line++;
	}
	return (nb_line);
}

int my_atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if(str[0] == '-') {
		sign = -1;
		i++;
	}
	for(; str[i] != '\0'; i++)
		res = res * 10 + str[i] - '0';
	return (sign*res);
}
