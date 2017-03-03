/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:25:08 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 10:50:34 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_fd_error(t_env *e, int fd)
{
	ft_putstr_fd("fd isn't a valid open file descriptor\n", 2);
	close(fd);
	e = fdf_mlx_del(e);
	ft_memdel((void**)&e);
	exit(1);
}

void	fdf_del_point(t_env *e)
{
	int j;

	j = 0;
	while (e->map[j])
	{
		free(e->map[j]);
		e->map[j] = NULL;
		j++;
	}
}

void	cleanup(char **str)
{
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
}

void	fdf_read_error(t_env *e, char **tmp)
{
	ft_putstr_fd("Wrong map\n", 2);
	cleanup(tmp);
	ft_memdel((void**)tmp);
	fdf_mlx_del(e);
	exit(1);
}

void	fdf_malloc_error(t_env *e)
{
	ft_putstr_fd("Malloc error\n", 2);
	e = fdf_mlx_del(e);
	fdf_del_point(e);
	ft_memdel((void**)(e->map));
	ft_memdel((void**)&e);
	exit(1);
}
