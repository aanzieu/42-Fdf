/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:21:45 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 09:46:58 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_image		*new_image(t_env *e)
{
	t_image *img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGTH)))
		return (del_image(e, img));
	img->img_s = mlx_get_data_addr(img->img, &img->bpp, &img->s_l,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

static void	init_env_next(t_env *e)
{
	e->min_z = 0;
	e->max_z = 0;
	e->max_h = 0;
	e->max_w = 0;
	e->fovy = 0;
	e->near = 5;
	e->far = 5;
	e->ud = 1;
	e->lr = 1;
	e->opt = ISO;
	e->method = IMG;
	ft_bzero(e->z_buff, WIN_WIDTH * WIN_HEIGTH);
	e->color_max = init_color(255, 0, 0);
	e->color_min = init_color(128, 128, 128);
}

t_env		*init_env(char *argv)
{
	t_env	*e;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(1);
	}
	if ((e->mlx = mlx_init()) == NULL
		|| (e->win = mlx_new_window(e->mlx,
		WIN_WIDTH, WIN_HEIGTH, "FdF aanzieu")) == NULL
		|| (e->image = new_image(e)) == NULL)
		return (fdf_mlx_del(e));
	e->arg = argv;
	init_env_next(e);
	e->map = fdf_read(e);
	return (e);
}
