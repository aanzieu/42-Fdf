/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:37:49 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 16:37:50 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel_color(int x, int y, t_env *e, t_color *color)
{
	if (is_inside(x, y, e))
		mlx_pixel_put(e->mlx, e->win, x + (e->height / 2), y + (e->width / 2),
				convert_color(color));
}

void	generate2d(t_env *e)
{
	t_m3	*p;
	t_m3	*d2;
	t_m3	*tmp;

	tmp = NULL;
	p = e->p;
	while (p != NULL)
	{
		d2 = calculate_point(p, e->cam, e);
		d2->z = p->z;
		if (tmp != NULL)
			tmp->next = d2;
		else
			e->d2 = d2;
		tmp = d2;
		p = p->next;
	}
}

t_m3	*get_point_left(t_m3 *a, int i)
{
	int		e;

	e = 0;
	while (a->end == 0)
	{
		if (a->next == NULL)
			return (NULL);
		a = a->next;
	}
	while (--i > -2)
	{
		if (e == 0)
			e++;
		else
		{
			if (a->end == 1)
				return (NULL);
		}
		if (a->next == NULL)
			return (NULL);
		a = a->next;
	}
	return (a);
}

void	draw(t_env *e)
{
	t_m3	*d2;
	t_m3	*left;
	int		i;

	i = 0;
	clear(e);
	info(e);
	generate2d(e);
	d2 = e->d2;
	while (d2 != NULL)
	{
		left = get_point_left(d2, i);
		if (left != NULL)
			drawline(d2, left, e);
		if (d2->end == 0)
			drawline(d2, d2->next, e);
		else
			i = -1;
		i++;
		d2 = d2->next;
	}
}

void	clear(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	return ;
}
