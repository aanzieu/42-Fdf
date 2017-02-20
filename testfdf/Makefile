#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:41:24 by adespond          #+#    #+#              #
#    Updated: 2017/02/20 11:23:00 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= src/main.c \
		  src/key.c \
		  src/draw.c \
		  src/point.c \
		  src/init.c \
		  src/drawline.c \
		  src/read.c \
		  src/calculate.c \
		  src/expose.c \
		  src/info.c \
		  src/color.c \
		  src/utils.c \
		  src/close.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L ./minilibx_macos/ -L ./libft/ -lft 
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all test
