##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/find_biggest_square.c		\
			src/display_final_result.c		\
			src/load_2d_array_from_file.c	\
			src/mem_alloc_2d_array.c		\
			src/get_map_size.c				\
			src/full_obstacle_map.c			\
			src/mem_free_2d_array.c			\
			src/error.c						\
			src/main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	+=	-Wall -Werror -Wshadow -Wshadow -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
			make re -C lib/my/
			cc $(OBJ) -o $(NAME) -L./lib/ -lmy

unit_tests:	$(OBJ)
			make re -C lib/my/
			make re -C tests/

run_tests:
			./tests/unit_tests


clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			make fclean -C tests/
			make fclean -C lib/my/
			rm lib/libmy.a
			rm *.gcno
			rm *.gcda

re:
			fclean all