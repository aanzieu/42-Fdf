/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:38:00 by aanzieu           #+#    #+#             */
/*   Updated: 2017/02/20 18:09:20 by aanzieu          ###   ########.fr       */
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

void	new_point(int x, int y, double z, t_env *e)
{
	t_map	*p;
	t_map	*tmp;

	if(!(p = (t_map*)malloc(sizeof(t_map))))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	p->x = x;
	p->y = y;
	p->z = z;
	p->end = 0;
	p->next = NULL;
	if ((tmp = e->p) == NULL)
	{
		e->p = p;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = p;
}

int		read_line(char *line, t_env *e, int x, int y)
{
	int		z;
	char	**tmp;
	
	tmp = ft_strsplit(line, ' ');
	while (tmp[x])
	{
		z = ft_getnbr(tmp[x]);
		new_point(x, y, z, e);
		if (z < e->min_z)
			e->min_z = z;
		if (z > e->max_z)
			e->max_z = z;
		x++;
	}
	return (x);
}

void	fdf_read(t_env *e, char *argv)
{
	int			max_y;
	int			max_x;
	char		*line;

	max_x = 0;
	max_y = 0;
	if((e->fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr_fd("FD error\n", 2);
		close(e->fd);
		exit(1);
	}
	while(get_next_line(e->fd, &line) == 1)
	{
		max_x = read_line(line, e, 0, max_y);
		max_y++;
	}
	if (max_x > e->max_x)
			e->max_x = max_x;
	e->max_y = max_y;
	close(e->fd);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if(argc == 2)
	{
		if(!(e = (t_env*)malloc(sizeof(t_env))))
		{
			ft_putstr_fd("malloc error\n", 2);
			exit(1);
		}
		fdf_read(e, argv[1]);
	}
	return (0);
}
