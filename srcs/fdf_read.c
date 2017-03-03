/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/02 13:51:12 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_point		new_point(char *str, int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = ft_atoi(str);
	return (p);
}

static	void		read_line_tmp(char **tmp, t_env *e, t_point *p, int y)
{
	int		x;

	x = 0;
	while (tmp[x] != NULL)
	{
		if (!(search_error(tmp[x])))
			fdf_read_error(e, tmp);
		e->max_z = ((ft_atoi(tmp[x])) > e->max_z) ? ft_atoi(tmp[x]) : e->max_z;
		e->min_z = ((ft_atoi(tmp[x])) < e->min_z) ? ft_atoi(tmp[x]) : e->min_z;
		p[x] = new_point(tmp[x], x, y);
		x++;
	}
	while (x < e->max_w)
	{
		p[x] = new_point("0", x, y);
		x++;
	}
}

static t_point		*read_line_fdf(char *line, t_env *e, int y)
{
	t_point	*p;
	char	**tmp;
	int		size;

	tmp = ft_strsplit(line, ' ');
	size = ft_count_p((void**)tmp);
	e->max_w = (size > e->max_w) ? size : e->max_w;
	if (!(p = (t_point *)ft_memalloc(sizeof(t_point) * (e->max_w + 1))))
		fdf_malloc_error(e);
	read_line_tmp(tmp, e, p, y);
	cleanup(tmp);
	ft_memdel((void **)&tmp);
	return (p);
}

t_point				**fdf_read(t_env *e)
{
	int		y;
	char	*line;
	int		fd;
	t_point	**grid;

	y = 0;
	if ((fd = open(e->arg, O_RDONLY)) < 0)
		fdf_fd_error(e, fd);
	if (!(grid = (t_point **)ft_memalloc(sizeof(t_point *)
					* (ft_len_tab(e) + 1))))
		fdf_malloc_error(e);
	while (get_next_line(fd, &line) == 1)
	{
		grid[y] = read_line_fdf(line, e, y);
		free(line);
		y++;
	}
	grid[y] = read_line_fdf(line, e, y);
	close(fd);
	free(line);
	e->max_h = ft_count_p((void**)(grid));
	return (grid);
}
