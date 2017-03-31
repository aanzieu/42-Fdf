/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:38:00 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 16:28:15 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		expose_hook(t_env *e)
{
	if (e->method == DRAW)
		mlx_clear_window(e->mlx, e->win);
	calcul_point(e);
	draw_map(e);
	if (e->method == IMG)
		mlx_put_image_to_window(e->mlx, e->win, e->image->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 2 || argc >= 4)
		fdf_too_many_arg(argc);
	if (argc == 2)
		e = init_env(argv[1]);
	if (argc == 3)
	{
		e = init_env(argv[1]);
		if (set_color(argv[2], e) == 1)
		{
			ft_putstr_fd("Format Colors : RRRGGGBBBRRRGGGBBB\n", 2);
			ft_putstr_fd("Value  Colors : =< 0 & <= 255\n", 2);
			ft_memdel((void**)&e);
			return (0);
		}
	}
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
