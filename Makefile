##
## EPITECH PROJECT, 2023
## MyHunter Makefile
## File description:
## Makefile
##

SRC	=	./src/my_hunter.c	\
		./src/game.c		\
		./src/init_menu.c	\
		./src/init_game.c	\
		./src/my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
