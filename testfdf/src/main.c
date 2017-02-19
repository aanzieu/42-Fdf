/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:59:16 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 16:57:48 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	read_option(int argc, char **argv, t_env *e)
{
	if (argc < 2)
	{
		write(1, "Usage <filename> [RRRGGGBBBAAA-RRRGGGBBBAAA] [OCEAN]\n", 53);
		return (1);
	}
	if (open_file(e, argv[1]) == 0)
	{
		write(1, "Map error\n", 11);
		return (1);
	}
	if (argc >= 3 && set_color(argv[2], e) == 1)
	{
		write(1, "Error color format [RRRGGGBBBAAA-RRRGGGBBBAAA]\n", 47);
		write(1, "      RRR or GGG or BBB or AAA >= 0 AND <= 255\n", 47);
		return (1);
	}
	if (argc == 4 && ft_strcmp(argv[3], "1") == 0)
		e->ocean = 1;
	return (0);
}

int			main(int argc, char **argv)
{
	t_env		*e;

	e = init_env();
	if (read_option(argc, argv, e) == 1)
		return (0);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	init_first_cam(e);
	draw(e);
	mlx_loop(e->mlx);
	return (0);
}
