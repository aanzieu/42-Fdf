/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:39:35 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/16 12:11:53 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../srcs/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_env
{
		void	*mlx;
		void	*win;
		char	*line;
		int		fd;
}					t_env;

typedef	struct		s_fdf
{
	char	*nbr;
	int		x;
	int		y;
}					t_fdf;

#endif
