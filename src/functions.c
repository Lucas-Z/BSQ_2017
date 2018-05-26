/*
** EPITECH PROJECT, 2017
** function_part1
** File description:
** BSQ
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_strlen_to(char *str, char delimiter)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != delimiter) {
		i++;
	}
	return (i);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *my_putnstr(char *str, int size)
{
	write(1, str, size);
	return(str);
}

char *my_putstr(char *str)
{
	int index = 0;
	int strlen = 0;

	while(str[index] != '\0') {
		strlen++;
	}
	my_putnstr(str, strlen);
	return(str);
}
