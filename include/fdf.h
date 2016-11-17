/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:39:35 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/17 20:13:48 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define	WIN_WIDTH	1920
# define	WIN_HEIGTH	1080

typedef	struct	s_points
{
	double		x;
	double		y;
	double		z;
}				t_points;

typedef	struct	s_line
{
	t_points	**points;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**line;
	int			len;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*buf;
	int			fd;
}				t_env;


#endif
