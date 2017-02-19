echo "============make libft==============="
make -C srcs/libft/ fclean && make -C srcs/libft/
echo "done making libft"

echo "============FDF files upload==============="
gcc -Wall -Wextra -Werror -c fdf.c -I ./include/ -I ./minilibx_macos/
gcc -Wall -Wextra -Werror -g -o FDF fdf.o -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -I ./minilibx_macos/ -L ./srcs/libft/ -lft


echo "done"
rm "fdf.o"
./FDF test1
echo "\n=================TESTING DONE====================="
rm "FDF"
