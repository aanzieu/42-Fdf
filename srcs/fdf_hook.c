/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:45:00 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 09:46:27 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_fdf(t_env *e)
{
	e->method = DRAW;
	fdf_del(e);
}

void	put_img_fdf(t_env *e)
{
	e->method = IMG;
	fdf_del(e);
}

int		key_hook_opt(int button, t_env *e)
{
	if (button == 53)
	{
		fdf_mlx_del(e);
		fdf_del_point(e);
		ft_memdel((void**)(e->map));
		ft_memdel((void**)&e);
		exit(0);
	}
	if (button == 31)
		ortho_projection(e);
	if (button == 35)
		para_projection(e);
	if (button == 34)
		isometric_projection(e);
	if (button == 48)
		origin_projection(e);
	if (button == 1)
		spher_projection(e);
	if (button == 2)
		draw_fdf(e);
	if (button == 3)
		put_img_fdf(e);
	return (0);
}

int		key_hook(int button, t_env *e)
{
	if (button == 43)
		rotate_left(e);
	if (button == 47)
		rotate_right(e);
	if (button == 123)
		move_left(e);
	if (button == 124)
		move_right(e);
	if (button == 125)
		move_down(e);
	if (button == 126)
		move_up(e);
	if (button == 7)
		axe_x(e);
	if (button == 16)
		axe_y(e);
	if (button == 6)
		axe_z(e);
	key_hook_opt(button, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->far -= 1;
		fdf_del(e);
	}
	if (button == 5)
	{
		e->far += 1;
		fdf_del(e);
	}
	if (button == 1)
	{
		e->near = (e->near + 1.2 <= 0) ? e->near : e->near + 1.2;
		fdf_del(e);
	}
	if (button == 2)
	{
		e->near = (e->near - 1.2 <= 0) ? e->near : e->near - 1.2;
		fdf_del(e);
	}
	(void)x;
	(void)y;
	return (0);
}
