/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:58:58 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 15:26:41 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		key_rotation(int keycode, t_env *e)
{
	if (keycode == 17)
		e->cam->rx += 0.174533;
	if (keycode == 16)
		e->cam->rx -= 0.174533;
	if (keycode == 5)
		e->cam->ry += 0.174533;
	if (keycode == 4)
		e->cam->ry -= 0.174533;
	if (keycode == 45)
		e->cam->rz += 0.174533;
	if (keycode == 11)
		e->cam->rz -= 0.174533;
}

static void		key_move(int keycode, t_env *e)
{
	if (keycode == 13)
		e->cam->y += -e->max_x;
	if (keycode == 1)
		e->cam->y += +e->max_x;
	if (keycode == 0)
		e->cam->x += -e->max_x;
	if (keycode == 2)
		e->cam->x += e->max_x;
	if (keycode == 3)
		e->cam->z += e->max_x;
	if (keycode == 15)
		e->cam->z -= e->max_x;
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_close(e);
	}
	if (keycode == 18)
		e->cam->fov += -10;
	if (keycode == 19)
		e->cam->fov += 10;
	if (keycode == 20)
		e->space += -2;
	if (keycode == 21)
		e->space += 2;
	key_rotation(keycode, e);
	key_move(keycode, e);
	draw(e);
	return (0);
}
