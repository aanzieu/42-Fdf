/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:14:35 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 15:56:59 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_image *del_image(t_env *e, t_image *img)
{
	if(img != NULL)
	{
		if(img->img != NULL)
			mlx_destroy_image(e->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return(NULL);
}

t_env	*fdf_mlx_del(t_env *e)
{
	if(e->win != NULL)
		mlx_destroy_window(e->mlx, e->win);
	if(e->image != NULL)
		del_image(e, e->image);
	return (NULL);
}

void	fdf_del(t_env *e)
{
	ft_bzero(e->image->img_s, WIN_HEIGTH *  WIN_WIDTH * e->image->bpp);
	expose_hook(e);
}
