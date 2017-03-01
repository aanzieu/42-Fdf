/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:39:35 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 16:43:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../srcs/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define	WIN_WIDTH	1920
# define	WIN_HEIGTH	1080
# define	AXE_X		0
# define	AXE_Y		1
# define	AXE_Z		2
/*
** Structure point
*/

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			dx;
	int			dy;
	int			color;
}				t_point;

/*
** Structure Rotation
*/

typedef struct	s_rotation
{
	double		rx;
	double		ry;
	double		rz;
	double		px;
	double		py;
	double		pz;
}				t_rot;

/*
** Structure Bresenham
*/

typedef struct	s_bresenham
{
	double		dx;
	double		dy;
	double		sx;
	double		sy;
	double		d_err;
}				t_br;

/*
** Structure Image
*/

typedef	struct		s_image
{
	void			*img;
	char			*img_s;
	int				bpp;
	int				s_l;
	int				endian;
}					t_image;

/*
** Structure Environnement 
*/

typedef struct	s_env
{
/*
** mlx
*/
	void			*mlx;
	void			*win;
/*
** arg
*/
	char			*arg;
/*
** parsing
*/
	int				min_z;
	int				max_z;
	int				max_w;
	int				max_h;
	int				color;
	struct s_point	**map;
	struct s_image	*image;
/*
** cam
*/
	float			fovy; //(angle)
	int				near;
	int				far;
	int				updown;
	int				leftright;
	int				rotation;
}					t_env;

/*
** Read_FDF
*/
t_point		**fdf_read(t_env *e);
int		expose_hook(t_env *e);

/*
** Draw_FDF
*/
void		draw_map(t_env *e);

/*
** Utils_FDF
*/
int			ft_abs(int n);
int			ft_len_tab(t_env *e);
int			search_error(char *str);
int			ft_count_p(void **s);

/*
** Init_FDF
*/
t_env		*init_env(char *argv);
t_image		*new_image(t_env *e);


/*
** Calcul_FDF
*/
void		calcul_point(t_env *e);

/*
** Del_FDF
*/
void	fdf_del(t_env *e);
void	fdf_del_point(t_env *e);
t_image *del_image(t_env *e, t_image *img);
t_env	*fdf_mlx_del(t_env *e);
void	cleanup(char **str);

/*
** Error_FDF
*/
void	fdf_fd_error(t_env *e, int fd);
void	fdf_malloc_error(t_env *e);
void	fdf_read_error(t_env *e, char **tmp);

t_env	*init_env(char *argv);
int			mouse_hook(int	button, int	x, int y, t_env *e);
int			key_hook(int	button, t_env *e);

int			check_point(t_env *e, int x, int y);

#endif
