/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:39:35 by aanzieu           #+#    #+#             */
/*   Updated: 2017/02/20 17:30:04 by aanzieu          ###   ########.fr       */
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


typedef struct	s_map
{
	double			x;
	double			y;
	double			z;
	char			end;
	struct s_map	*next;
}					t_map;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				fd;

	int				min_z;
	int				max_z;
	int				max_x;
	int				max_y;
	
	struct s_map	*p;
	struct s_map	*matrice;

}					t_env;

#endif
