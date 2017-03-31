/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:44:31 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 13:43:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotation_z(t_env *e, t_rot *rot)
{
	rot->px = rot->rx * cos(e->fovy) + rot->ry * sin(e->fovy);
	rot->py = -rot->rx * sin(e->fovy) + rot->ry * cos(e->fovy);
	rot->pz = rot->rz;
}

void	rotation_y(t_env *e, t_rot *rot)
{
	rot->px = rot->rx * cos(e->fovy) - rot->rz * sin(e->fovy);
	rot->py = rot->ry;
	rot->pz = rot->rx * sin(e->fovy) + rot->rz * cos(e->fovy);
}

void	rotation_x(t_env *e, t_rot *rot)
{
	rot->px = rot->rx;
	rot->py = rot->ry * cos(e->fovy) - rot->rz * sin(e->fovy);
	rot->pz = -rot->ry * sin(e->fovy) + rot->rz * cos(e->fovy);
}

void	calcul_new_point(t_env *e, t_point *p)
{
	t_rot	*rot;

	if (!(rot = (t_rot *)ft_memalloc(sizeof(t_rot))))
		fdf_malloc_error(e);
	rot->rx = (p->x - (e->max_w / 2)) * e->far;
	rot->ry = (p->y - (e->max_h / 2)) * e->far;
	rot->rz = p->z * (e->near * 0.02);
	if (e->rotation == AXE_X)
		rotation_x(e, rot);
	else if (e->rotation == AXE_Y)
		rotation_y(e, rot);
	else
		rotation_z(e, rot);
	if (e->opt == PARA)
		para_proj(p, rot);
	if (e->opt == ISO)
		iso_proj(p, rot);
	if (e->opt == ORTHO)
		ortho_proj(p, rot);
	if (e->opt == SPHERE)
		sphere_projection(p, rot);
	ft_memdel((void **)&rot);
}

void	calcul_point(t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while (j < e->max_h)
	{
		i = 0;
		while (i < e->max_w)
		{
			calcul_new_point(e, &(e->map[j][i]));
			i++;
		}
		j++;
	}
}
