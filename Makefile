# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 08:51:13 by aanzieu           #+#    #+#              #
#    Updated: 2017/03/02 17:45:52 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

FLGS	= -Wall -Wextra -Werror

SRC		= srcs/fdf.c \
		  srcs/fdf_calc.c \
		  srcs/fdf_sphere.c \
		  srcs/fdf_colors.c \
		  srcs/fdf_del.c \
		  srcs/fdf_draw.c \
		  srcs/fdf_error.c \
		  srcs/fdf_hook.c \
		  srcs/fdf_init.c \
		  srcs/fdf_move.c \
		  srcs/fdf_projection.c \
		  srcs/fdf_read.c \
		  srcs/fdf_rotate.c \
		  srcs/fdf_utils.c \

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C srcs/libft/ 
	gcc $(FLGS) -o $(NAME) $(SRC) -I ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L ./minilibx_macos/ -L ./srcs/libft/ -lft 
	printf '\033[32m[✔] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[✔] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C srcs/libft/ clean
	printf '\033[31m[✔] %s\n\033[0m' "Clean Libft"

fclean: clean
	/bin/rm -f $(NAME)
	make -C srcs/libft/ fclean
	printf '\033[31m[✔] %s\n\033[0m' "Fclean Libft"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all test
