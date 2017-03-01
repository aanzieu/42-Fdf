/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:21:45 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 17:36:59 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_image		*new_image(t_env *e)
{
	t_image *img;

	if(!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return(NULL);
	if(!(img->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGTH)))
		return (del_image(e, img));
	img->img_s = mlx_get_data_addr(img->img, &img->bpp, &img->s_l,
			&img->endian);
	img->bpp /= 8;
	return(img);
}

t_env	*init_env(char *argv)
{
	t_env	*e;

	if(!(e = (t_env*)ft_memalloc(sizeof(t_env))))
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(1);
	}
	if ((e->mlx = mlx_init()) == NULL 
		|| (e->win = mlx_new_window(e->mlx,
		WIN_WIDTH, WIN_HEIGTH, "FdF aanzieu")) == NULL
		|| (e->image = new_image(e)) == NULL)
			return(fdf_mlx_del(e));
	e->arg = argv;
	e->min_z = 0;
	e->max_z = 0;
	e->max_h = 0;
	e->max_w = 0;
	e->fovy = 0;
	e->near = 15;
	e->far = 15;
	e->updown = 1;
	e->leftright = 1;
	e->map = fdf_read(e);
	return (e);
}
