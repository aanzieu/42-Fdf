/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:27:52 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 16:25:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_br		*algo_bresenham(t_env *e, t_point *a, t_point *b)
{
	t_br *algo;

	if (!(algo = (t_br *)ft_memalloc(sizeof(t_br))))
		fdf_malloc_error(e);
	algo->dx = ft_abs(b->dx - a->dx);
	algo->sx = a->dx < b->dx ? 1 : -1;
	algo->dy = ft_abs(b->dy - a->dy);
	algo->sy = a->dy < b->dy ? 1 : -1;
	algo->d_err = (algo->dx > algo->dy ? algo->dx : -(algo->dy)) / 2;
	return (algo);
}

static void		draw_p(t_env *e, int x, int y, int color)
{
	if (e->method == IMG)
	{
		ft_memcpy(&e->image->img_s[(x * 4) + (y * e->image->s_l)], &(color),
				(size_t)(sizeof(int)));
	}
	if (e->method == DRAW)
	{
		mlx_pixel_put(e->mlx, e->win, x, y, 0x00FFFFFF);
		usleep(5);
	}
}

static void		draw_line(t_env *e, t_point *a, t_point *b, int err)
{
	int		x;
	int		y;
	t_br	*bres;

	bres = algo_bresenham(e, a, b);
	x = a->dx;
	y = a->dy;
	while (1)
	{
		if (check_point(e, x, y))
			draw_p(e, x + e->lr, y + e->ud, conv_c(get_c(e, a, (double)a->z)));
		if (x == b->dx && y == b->dy)
			break ;
		if ((err = bres->d_err) > -(bres->dx))
		{
			bres->d_err -= bres->dy;
			x += bres->sx;
		}
		if (err < bres->dy)
		{
			bres->d_err += bres->dx;
			y += bres->sy;
		}
	}
	ft_memdel((void **)&bres);
}

void			draw_map(t_env *e)
{
	int i;
	int j;

	j = 0;
	while (j < e->max_h)
	{
		i = 0;
		while (i < e->max_w)
		{
			if (i < e->max_w - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j][i + 1]), 0);
			if (j < e->max_h - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j + 1][i]), 0);
			i++;
		}
		j++;
	}
}
