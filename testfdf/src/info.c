/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:34:17 by adespond          #+#    #+#             */
/*   Updated: 2016/01/29 11:50:22 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	info_cam(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(e->mlx, e->win, 10, 22, 0x00FFFFFF, "FOV :");
	mlx_string_put(e->mlx, e->win, 70, 22, 0x00FFFFFF, ft_itoa(e->cam->fov));
	mlx_string_put(e->mlx, e->win, 10, 34, 0x00FFFFFF, "  X :");
	mlx_string_put(e->mlx, e->win, 70, 34, 0x00FFFFFF, ft_itoa(e->cam->x));
	mlx_string_put(e->mlx, e->win, 10, 46, 0x00FFFFFF, "  Z :");
	mlx_string_put(e->mlx, e->win, 70, 46, 0x00FFFFFF, ft_itoa(e->cam->y));
	mlx_string_put(e->mlx, e->win, 10, 58, 0x00FFFFFF, "  Y :");
	mlx_string_put(e->mlx, e->win, 70, 58, 0x00FFFFFF, ft_itoa(e->cam->z));
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF, " rX :");
	mlx_string_put(e->mlx, e->win, 70, 70, 0x00FFFFFF, ft_itoa(e->cam->rx *
				57.2958));
	mlx_string_put(e->mlx, e->win, 10, 82, 0x00FFFFFF, " rY :");
	mlx_string_put(e->mlx, e->win, 70, 82, 0x00FFFFFF, ft_itoa(e->cam->ry *
				57.2958));
	mlx_string_put(e->mlx, e->win, 10, 94, 0x00FFFFFF, " rZ :");
	mlx_string_put(e->mlx, e->win, 70, 94, 0x00FFFFFF, ft_itoa(e->cam->rz *
				57.2958));
}

void	info_max_min(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 118, 0x00FFFFFF, "- MIN / MAX -");
	mlx_string_put(e->mlx, e->win, 10, 130, 0x00FFFFFF, "MIN :");
	mlx_string_put(e->mlx, e->win, 70, 130, 0x00FFFFFF, ft_itoa(e->min_z));
	mlx_string_put(e->mlx, e->win, 10, 142, 0x00FFFFFF, "MAX :");
	mlx_string_put(e->mlx, e->win, 70, 142, 0x00FFFFFF, ft_itoa(e->max_z));
	mlx_string_put(e->mlx, e->win, 10, 154, 0x00FFFFFF, "X   :");
	mlx_string_put(e->mlx, e->win, 70, 154, 0x00FFFFFF, ft_itoa(e->max_x));
	mlx_string_put(e->mlx, e->win, 10, 166, 0x00FFFFFF, "Y   :");
	mlx_string_put(e->mlx, e->win, 70, 166, 0x00FFFFFF, ft_itoa(e->max_y));
}

void	info_point(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 190, 0x00FFFFFF, "--- POINT ---");
	mlx_string_put(e->mlx, e->win, 10, 202, 0x00FFFFFF, "SPA :");
	mlx_string_put(e->mlx, e->win, 70, 202, 0x00FFFFFF, ft_itoa(e->space));
}

void	info(t_env *e)
{
	info_cam(e);
	info_max_min(e);
	info_point(e);
}
