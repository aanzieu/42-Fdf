/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:55:51 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 16:55:45 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_cam	*init_cam(void)
{
	t_cam	*c;

	c = (t_cam *)malloc(sizeof(t_cam));
	c->x = 0;
	c->y = 0;
	c->z = 0;
	c->rx = 0.7853981633973;
	c->ry = 0;
	c->rz = -0.7853981633973;
	c->fov = 1000;
	return (c);
}

t_env	*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->cam = init_cam();
	e->mlx = mlx_init();
	e->width = 1000;
	e->height = 1000;
	e->p = NULL;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "FdF adespond");
	e->space = 10;
	e->min_z = 0;
	e->max_z = 0;
	e->max_y = 0;
	e->max_x = 0;
	e->ocean = 0;
	e->color_min = init_color(255, 255, 255, 0);
	e->color_max = init_color(0, 102, 0, 0);
	return (e);
}

t_color	*init_color(int r, int g, int b, int a)
{
	t_color	*c;

	c = (t_color *)malloc(sizeof(t_color));
	c->r = r;
	c->g = g;
	c->b = b;
	c->a = a;
	return (c);
}

void	init_first_cam(t_env *e)
{
	e->cam->x = -10 * e->max_x;
	e->cam->y = -10 * e->max_y;
	e->cam->z = 10 * e->max_x;
}
