/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 09:51:20 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 13:43:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	sphere_projection(t_point *p, t_rot *rot)
{
	double	d;
	int		r;

	r = 500;
	d = sqrt(ft_sq(rot->px) + ft_sq(rot->py) + ft_sq(rot->pz));
	p->dx = (r * rot->px) / (sqrt(ft_sq(r) - 2 * r * rot->pz + ft_sq(d)))
		+ WIN_WIDTH * 0.5;
	p->dy = (r * rot->py) / (sqrt(ft_sq(r) - 2 * r * rot->pz + ft_sq(d)))
		+ WIN_HEIGTH * 0.5;
}

void	para_proj(t_point *p, t_rot *rot)
{
	p->dx = rot->px + (1 * rot->pz) + (WIN_WIDTH * 0.5);
	p->dy = (rot->py) + ((1 * 0.5) * rot->pz) + (WIN_HEIGTH * 0.5);
}

void	iso_proj(t_point *p, t_rot *rot)
{
	p->dx = (rot->px - rot->py) + (WIN_WIDTH * 0.5);
	p->dy = (-rot->pz + rot->px * 0.5 + rot->py * 0.5) + (WIN_HEIGTH * 0.5);
}

void	ortho_proj(t_point *p, t_rot *rot)
{
	p->dx = (rot->px + (0.5 * cos(rot->py))) + WIN_WIDTH * 0.5;
	p->dy = (-rot->pz + (0.5 * sin(rot->py))) + WIN_HEIGTH * 0.5;
}

int		check_point(t_env *e, int x, int y)
{
	return ((x + e->lr) < WIN_WIDTH
			&& (x + e->lr) > 0
			&& (y + e->ud) < WIN_HEIGTH
			&& (y + e->ud) > 0);
}
