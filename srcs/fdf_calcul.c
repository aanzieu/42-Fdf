/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:50:30 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 17:41:09 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotation_z(t_env *e, t_rot *rot)
{
	rot->px = rot->rx * cos(e->fovy) - rot->ry * sin(e->fovy);
	rot->py = rot->rx * sin(e->fovy) + rot->ry * cos(e->fovy);
	rot->pz = rot->rz;
}

void	rotation_y(t_env *e, t_rot *rot)
{
	rot->px = rot->rx * cos(e->fovy) + rot->rz * sin(e->fovy);
	rot->py = rot->ry;
	rot->pz = rot->rx * -sin(e->fovy) + rot->rz * cos(e->fovy);
}

void	rotation_x(t_env *e, t_rot *rot)
{
	rot->px = rot->rx;
	rot->py = rot->ry * cos(e->fovy) - rot->rz * sin(e->fovy);
	rot->pz = rot->ry * sin(e->fovy) + rot->rz * cos(e->fovy);
}

static void	calcul_new_point(t_env *e, t_point *p)
{
	t_rot	*rot;

	if (!(rot = (t_rot *)ft_memalloc(sizeof(t_rot))))
		fdf_malloc_error(e);
	rot->rx = p->x * e->far - (hypot(e->max_h, e->max_w));
	rot->ry = p->y * e->far - (hypot(e->max_h, e->max_w));
	rot->rz = p->z * e->far * 0.4;
	
	if(e->rotation == AXE_Z)
		rotation_z(e, rot);
	else if(e->rotation == AXE_Y)
		rotation_y(e, rot);
	else
		rotation_x(e, rot);
	p->dx = rot->px + rot->pz + WIN_WIDTH * 0.5;
	p->dy = -rot->py + -1 * 0.5 * rot->pz + WIN_HEIGTH * 0.5;
//	p->dx = (rot->px - rot->py) + WIN_WIDTH * 0.5;
//	p->dy = (-rot->pz + rot->px * 0.5 + rot->py * 0.5) + WIN_HEIGTH * 0.5;
	ft_memdel((void **)&rot);
}

void	calcul_point(t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while(j < e->max_h)
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
