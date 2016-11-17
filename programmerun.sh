echo "============make libft==============="
make -C srcs/libft/ fclean && make -C srcs/libft/
echo "done making libft"

echo "============FDF files upload==============="
gcc -Wall -Wextra -Werror -g -I srcs/libft/ -c fdf.c -I include
gcc -Wall -Wextra -Werror -g -o FDF fdf.o srcs/libft/libft.a -lmlx -lXext -lX11

echo "done"
rm "fdf.o"
./FDF test1
echo "\n=================TESTING DONE====================="
rm "FDF"
