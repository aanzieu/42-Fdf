/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:02:29 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 16:47:44 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int	convert_color(t_color *color)
{
	unsigned int	ret;

	ret = (color->a << 24) + (color->r << 16) + (color->g << 8) + color->b;
	return (ret);
}

t_color			*get_color(t_env *e, double z)
{
	double		r;
	double		g;
	double		b;
	double		a;

	if (e->ocean == 1 && z <= 0)
	{
		e->min_z = 0;
		return (init_color(0, 0, 150, 0));
	}
	if (e->min_z < 0)
		z = z + -e->min_z;
	if (e->min_z == 0 && e->max_z == 0)
		return (init_color(254, 254, 254, 0));
	r = ((((double)e->color_min->r - e->color_max->r) / abs(e->min_z -
					e->max_z)) * z) + e->color_max->r;
	g = ((((double)e->color_min->g - e->color_max->g) / abs(e->min_z -
					e->max_z)) * z) + e->color_max->g;
	b = ((((double)e->color_min->b - e->color_max->b) / abs(e->min_z -
					e->max_z)) * z) + e->color_max->b;
	a = ((((double)e->color_min->a - e->color_max->a) / abs(e->min_z -
					e->max_z)) * z) + e->color_max->a;
	return (init_color(r, g, b, a));
}

char			set_color(char *s, t_env *e)
{
	int		i;

	i = -1;
	if (ft_strlen(s) != 25 || s[12] != '-')
		return (1);
	while (s[++i] != '\0')
	{
		if (i != 12 && (s[i] > '9' || s[i] < '0'))
			return (1);
	}
	e->color_max->r = ft_atoi(ft_strsub(s, 0, 3));
	e->color_max->g = ft_atoi(ft_strsub(s, 3, 3));
	e->color_max->b = ft_atoi(ft_strsub(s, 6, 3));
	e->color_max->a = ft_atoi(ft_strsub(s, 9, 3));
	e->color_min->r = ft_atoi(ft_strsub(s, 13, 3));
	e->color_min->g = ft_atoi(ft_strsub(s, 16, 3));
	e->color_min->b = ft_atoi(ft_strsub(s, 19, 3));
	e->color_min->a = ft_atoi(ft_strsub(s, 22, 3));
	ft_putchar('a');
	return (0);
}
