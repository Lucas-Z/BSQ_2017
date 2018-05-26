##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## BSQ
##

SRC	=	src/main.c		\
		src/functions.c		\
		src/functions2.c	\
		src/min_max_value.c	\
		src/algo_minesweeper.c	\
		src/char_tab.c		\
		src/int_tab.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS	=	-I include/

NAME	=	bsq

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all re fclean clean
