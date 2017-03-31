/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:23:15 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/13 11:40:06 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void			chearch_colors(t_point *p, char *str)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	i = 0;
	while (str && str[i] && str[i] != ',')
	{
		if (str[i] == ',')
		{
			i++;
			tmp = ft_strnew(ft_strlen(str));
			while (str && str[i])
			{
				tmp[j] = str[i];
				i++;
				j++;
			}
			p->col = 1;
			p->color = ft_atoi(ft_convert_base(tmp, HEXA, DEC));
			free(tmp);
		}
		i++;
	}
}

static t_point		new_point(char *str, int x, int y)
{
	t_point	p;

	chearch_colors(&p, str);
	p.x = x;
	p.y = y;
	p.z = ft_atoi(str);
	return (p);
}

static	void		read_line_tmp(char **tmp, t_env *e, t_point *p, int y)
{
	int		x;

	x = 0;
	if (!tmp[x])
	{
		ft_putstr_fd("Wrong Map\n", 2);
		exit(1);
	}
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

	tmp = ft_strsplit(line, ' ');
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
	grid[y] = NULL;
	close(fd);
	free(line);
	e->max_h = ft_count_p((void**)(grid));
	return (grid);
}
