/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:21:45 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 13:40:24 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		first_read_next(char *line, t_env *e)
{
	char	**tmp;
	int		size;

	tmp = ft_strsplit(line, ' ');
	size = ft_count_p((void**)tmp);
	e->max_w = (size > e->max_w) ? size : e->max_w;
	cleanup(tmp);
	ft_memdel((void **)&tmp);
}

void		first_read(t_env *e)
{
	char	*line;
	int		fd;

	if ((fd = open(e->arg, O_RDONLY)) < 0)
		fdf_fd_error(e, fd);
	while (get_next_line(fd, &line) == 1)
	{
		first_read_next(line, e);
		free(line);
	}
	free(line);
	close(fd);
}

t_image		*new_image(t_env *e)
{
	t_image *img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGTH)))
		return (del_image(e, img));
	img->img_s = mlx_get_data_addr(img->img, &img->bpp, &img->s_l,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

static void	init_env_next(t_env *e)
{
	e->min_z = 0;
	e->max_z = 0;
	e->max_h = 0;
	e->max_w = 0;
	e->fovy = 0;
	e->near = 5;
	e->far = 5;
	e->ud = 1;
	e->lr = 1;
	e->opt = ISO;
	e->method = IMG;
	ft_bzero(e->z_buff, WIN_WIDTH * WIN_HEIGTH);
	e->color_max = init_color(255, 255, 0);
	e->color_min = init_color(102, 0, 153);
}

t_env		*init_env(char *argv)
{
	t_env	*e;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(1);
	}
	if ((e->mlx = mlx_init()) == NULL
		|| (e->win = mlx_new_window(e->mlx,
		WIN_WIDTH, WIN_HEIGTH, "FdF aanzieu")) == NULL
		|| (e->image = new_image(e)) == NULL)
		return (fdf_mlx_del(e));
	e->arg = argv;
	init_env_next(e);
	first_read(e);
	e->map = fdf_read(e);
	return (e);
}
