/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:38:00 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 16:07:18 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		expose_hook(t_env *e)
{
		calcul_point(e);
		draw_map(e);
		mlx_put_image_to_window(e->mlx, e->win, e->image->img, 0, 0);
		return(0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	
	if(argc == 2)
	{
		e = init_env(argv[1]);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_mouse_hook(e->win, mouse_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
