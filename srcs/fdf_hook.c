/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:45:00 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 16:50:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//void		mouse_move_up(t_env *e)
//{
//	e->near = (e->near + 1.2 <= 0) ? e->near_
//
//}
/*
void		zoom_fdf(t_env *e)
{
	e->far += 1;
	fdf_del(e);
}
*/
void	rotate_left(t_env *e)
{
	e->fovy += 0.05;
	fdf_del(e);
}
void	rotate_right(t_env *e)
{
	e->fovy -= 0.05;
	fdf_del(e);
}

int			key_hook(int	button, t_env *e)
{
	if (button == 53)
	{
		fdf_mlx_del(e);
		fdf_del_point(e);
		ft_memdel((void**)(e->map));
		ft_memdel((void**)&e);
		exit(0);
	}
	if (button == 123)
		rotate_left(e);
	if (button == 124)
		rotate_right(e);
	return(0);
}

int			mouse_hook(int	button, int	x, int y, t_env *e)
{
	if (button == 4)
	{
		e->far += 1;
		fdf_del(e);
	}
	if (button == 5)
	{
		e->far -= 1;
		fdf_del(e);
	}
	(void)x;
	(void)y;
	return(0);
}
