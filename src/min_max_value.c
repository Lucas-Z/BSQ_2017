/*
** EPITECH PROJECT, 2017
** comparaison_value
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

int my_max(int a, int b)
{
	return (a > b) ? a : b;
}

int my_min(int b, int c)
{
	return (b < c) ? b : c;
}

int my_min_ter(int a, int b, int c)
{
	return my_min(a, my_min(b, c));
}
