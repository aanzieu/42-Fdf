/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 09:50:10 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 09:50:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include//fdf.h"

void	axe_x(t_env *e)
{
	e->rotation = AXE_X;
	fdf_del(e);
}

void	axe_y(t_env *e)
{
	e->rotation = AXE_Y;
	fdf_del(e);
}

void	axe_z(t_env *e)
{
	e->rotation = AXE_Z;
	fdf_del(e);
}

void	move_up(t_env *e)
{
	e->ud -= 10;
	fdf_del(e);
}

void	move_down(t_env *e)
{
	e->ud += 10;
	fdf_del(e);
}
