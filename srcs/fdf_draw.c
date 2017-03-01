/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:27:52 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 12:23:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		check_point(t_env *e, int x, int y)
{
	return ((x + e->leftright) < WIN_WIDTH
			&& (x + e->leftright) > 0
			&& (y + e->updown) < WIN_HEIGTH
			&& (y + e->updown) > 0);
}

static t_br		*algo_bresenham(t_point *a, t_point *b)
{
	t_br *algo;

	if(!(algo = (t_br *)ft_memalloc(sizeof(t_br))))
		return(NULL);
	algo->dx = ft_abs(b->dx - a->dx);
	algo->sx = a->dx < b->dx ? 1 : -1;
	algo->dy = ft_abs(b->dy - a->dy);
	algo->sy = a->dy < b->dy ? 1 : -1;
	algo->d_err = (algo->dx > algo->dy ? algo->dx : -(algo->dy)) / 2;
	a->color = 0x0041FF;
	//choose_color(a->z, b->z, max);
	return (algo);
}

static void		draw_point(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->image->img_s[(x * 4) + (y * e->image->s_l)], &(color), (size_t)(sizeof(int)));
}

static void		draw_line(t_env *e, t_point *a, t_point *b)
{
	int		x;
	int		y;
	int		err;
	t_br	*bres;

	if(!(bres = algo_bresenham(a, b)))
		fdf_malloc_error(e);
	x = a->dx;
	y = a->dy;
	while (1)
	{
		if (check_point(e, x, y))
			draw_point(e, x + e->leftright, y + e->updown, a->color);
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

void		draw_map(t_env *e)
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
				draw_line(e, &(e->map[j][i]), &(e->map[j][i + 1]));
			if (j < e->max_h - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j + 1][i]));
			i++;
		}
		j++;
	}
}
