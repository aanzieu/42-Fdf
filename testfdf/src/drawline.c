/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:38:40 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 11:55:17 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		drawline_error(t_env *e, t_m3 *a, t_m3 *b)
{
	if (a->x < -e->width || a->y < -e->height || a->x > e->width || a->y >
			e->height)
		return (1);
	if (b->x < -e->width || b->y < -e->height || b->x > e->width || b->y >
			e->height)
		return (1);
	if (is_inside(a->x, a->y, e) == 0 && is_inside(b->x, b->y, e) == 0)
		return (1);
	return (0);
}

static void		drawline_point(int step, t_m3 *a, t_m3 *b, t_env *e)
{
	int			i;
	double		xi;
	double		yi;
	float		z;
	t_m3		*pix;

	pix = new_m3(a->x, a->y, 0, 0);
	xi = (double)(b->x - a->x) / step;
	yi = (double)(b->y - a->y) / step;
	z = fabs((float)(a->z - b->z)) / step;
	i = -1;
	while (++i <= step)
	{
		if (a->z <= b->z)
			put_pixel_color(pix->x, pix->y, e, get_color(e, (double)a->z + z *
						i));
		else
			put_pixel_color(pix->x, pix->y, e, get_color(e, (double)a->z - z *
						i));
		pix->x = a->x + round((double)i * xi);
		pix->y = a->y + round((double)i * yi);
	}
	free(pix);
}

void			drawline(t_m3 *a, t_m3 *b, t_env *e)
{
	int			step;

	if (drawline_error(e, a, b) == 1)
		return ;
	if (fabs(a->x - b->x) <= fabs(a->y - b->y))
		step = 1 + fabs(a->y - b->y);
	else
		step = 1 + fabs(a->x - b->x);
	drawline_point(step, a, b, e);
}
