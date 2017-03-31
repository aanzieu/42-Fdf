/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 08:44:39 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/13 11:37:31 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				set_color(char *s, t_env *e)
{
	int		i;
	char	*tmp[6];

	i = -1;
	if (ft_strlen(s) != 18)
		return (1);
	while (s[++i] != '\0')
	{
		if ((s[i] > '9' || s[i] < '0'))
			return (1);
	}
	i = -1;
	while (++i < 6)
		tmp[i] = ft_strsub(s, i, i + 3);
	tmp[i] = NULL;
	e->color_max->r = ft_atoi(tmp[0]);
	e->color_max->g = ft_atoi(tmp[1]);
	e->color_max->b = ft_atoi(tmp[2]);
	e->color_min->r = ft_atoi(tmp[3]);
	e->color_min->g = ft_atoi(tmp[4]);
	e->color_min->b = ft_atoi(tmp[5]);
	cleanup(tmp);
	ft_memdel((void**)tmp);
	return (0);
}

unsigned int	conv_c(t_color *color)
{
	unsigned int	ret;

	ret = (256 * 256 * color->r + 256 * color->g + color->b);
	ft_memdel((void**)&color);
	return (ret);
}

t_color			*init_color(int r, int g, int b)
{
	t_color *color;

	if (!(color = (t_color *)ft_memalloc(sizeof(color))))
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_color			*get_c(t_env *e, t_point *a, double z)
{
	double		r;
	double		g;
	double		b;

	if (a->col == 1)
	{
		r = (a->color >> 16) & 0xFF;
		g = (a->color >> 8) & 0xFF;
		b = a->color & 0xFF;
		return (init_color(r, g, b));
	}
	if (e->min_z < 0)
		z = z + -e->min_z;
	if (e->min_z == 0 && e->max_z == 0)
		return (init_color(255, 255, 255));
	r = ((((double)e->color_min->r - e->color_max->r)
				/ ft_abs(e->min_z - e->max_z)) * z) + e->color_max->r;
	g = ((((double)e->color_min->g - e->color_max->g) /
				ft_abs(e->min_z - e->max_z)) * z) + e->color_max->g;
	b = ((((double)e->color_min->b - e->color_max->b) /
				ft_abs(e->min_z - e->max_z)) * z) + e->color_max->b;
	return (init_color(r, g, b));
}
