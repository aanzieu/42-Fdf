/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:38:00 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/17 21:50:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_getnbr(char *str)
{
	int   i;
	int   nbr;
	int		neg;

	nbr = 0;
	i = 0;
	neg = 1;
	while (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str && ft_isdigit(str[i]))
	{
		nbr = ((nbr * 10) + (str[i] - 48));
		i++;
	}
	return (neg * nbr);
}
int			ft_line(char *line,t_points ***point, int nbline)
{
	int		size;
	char	**tmp;
	t_points	*tab_points;
	
	tmp = ft_strsplit(line, ' ');
	size = 0;
	while (tmp[size])
		size++;
	if(!((*point) = (t_points**)malloc(sizeof(t_points) * size)))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	size = 0;
	while (tmp[size])
	{
		tab_points = (t_points*)malloc(sizeof(t_points));
		tab_points->x = size;
		tab_points->y = nbline;
		tab_points->z = ft_getnbr(tmp[size]);
		(*point)[size] = tab_points;
		size++;
	}

	return (size);
}

void		ft_init_map(t_env *env, t_map *map, char *argv)
{
	int		nbline;
	char	buf;

	nbline = 0;
	if((env->fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr_fd("FD error\n", 2);
		close(env->fd);
		exit(1);
	}
	while(read(env->fd, &buf, 1))
	{
		if (buf == '\n')
			nbline++;
	}
	if (!(map->line = (t_line**)malloc(sizeof(t_line) * nbline)))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	close(env->fd);
}

t_map		*fdf_read(t_env *env, char *argv)
{
	t_line		*tab_line;
	t_map		*map;
	t_points	**point;
	int			nbline;
	char		*line;

	int i;	
	if (!(map = (t_map*)malloc(sizeof(t_map))))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	ft_init_map(env, map, argv);
	nbline = 0;
	if((env->fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr_fd("FD error\n", 2);
		close(env->fd);
		exit(1);
	}
	while(get_next_line(env->fd, &line))
	{
		if(!(tab_line = (t_line*)malloc(sizeof(t_line))))
		{
			ft_putstr_fd("malloc error\n", 2);
			exit(1);
		}
		tab_line->len = ft_line(line, &point, nbline);
		printf("====================================\n");
		printf("Ligne :%d ---- :%s\n", nbline, line);
		printf("Ligne :%d size :%d\n", nbline, tab_line->len);
		tab_line->points = point;
		map->line[nbline] = tab_line;
		i = 0;
		while(i < tab_line->len)
		{
			printf("tab :%d x--- :%f y--- :%f z--- :%f\n", i, tab_line->points[i]->x, tab_line->points[i]->y, tab_line->points[i]->z);
			i++;
		}
		nbline++;
	}
	map->len = nbline;
	close(env->fd);
	write(1, "erreur ici", 11);
	return(map);
}

int		main(int argc, char **argv)
{
	t_env	*env;
	t_map	*matrice;

	if(argc == 2)
	{
		if(!(env = (t_env*)malloc(sizeof(t_env))))
		{
			ft_putstr_fd("malloc error\n", 2);
			exit(1);
		}
		matrice = fdf_read(env, argv[1]);
		printf("size final de matrice :%d ", matrice->len);
	}
	return (0);
}
