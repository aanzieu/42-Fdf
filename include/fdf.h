/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:39:35 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/21 13:37:10 by aanzieu          ###   ########.fr       */
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

# define WIN_WIDTH	1920
# define WIN_HEIGTH	1080
# define AXE_X		2
# define AXE_Y		1
# define AXE_Z		0
# define ISO		0
# define PARA		1
# define ORTHO		2
# define SPHERE		3
# define IMG		1
# define DRAW		2

# define HEXA		"0123456789ABCDEF"
# define DEC		"0123456789"

/*
** Structure point
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				dx;
	int				dy;
	int				color;
	int				col;
}					t_point;

/*
** Structure Rotation
*/

typedef struct		s_rotation
{
	double			rx;
	double			ry;
	double			rz;
	double			px;
	double			py;
	double			pz;
}					t_rot;

/*
** Structure Bresenham
*/

typedef struct		s_bresenham
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	double			d_err;
}					t_br;

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
** Structure Colors
*/

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

/*
** Structure Environnement
*/

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*arg;
	int				min_z;
	int				max_z;
	int				max_w;
	int				max_h;
	int				color;
	float			fovy;
	int				opt;
	int				near;
	int				far;
	int				ud;
	int				lr;
	int				rotation;
	int				method;
	float			z_buff[WIN_WIDTH * WIN_HEIGTH];
	struct s_color	*color_min;
	struct s_color	*color_max;
	struct s_point	**map;
	struct s_image	*image;
}					t_env;

/*
** Read_FDF
*/

t_point				**fdf_read(t_env *e);
int					expose_hook(t_env *e);

/*
** Draw_FDF
*/

void				draw_map(t_env *e);

/*
** Utils_FDF
*/

int					ft_abs(int n);
int					ft_len_tab(t_env *e);
int					search_error(char *str);
int					ft_count_p(void **s);
int					check_point(t_env *e, int x, int y);
int					ft_sq(int x);

/*
** Init_FDF
*/

t_env				*init_env(char *argv);
t_image				*new_image(t_env *e);

/*
** Calcul_FDF
*/

void				calcul_point(t_env *e);

/*
** Del_FDF
*/

void				fdf_del(t_env *e);
void				fdf_del_point(t_env *e);
t_image				*del_image(t_env *e, t_image *img);
t_env				*fdf_mlx_del(t_env *e);
void				cleanup(char **str);

/*
** Error_FDF
*/

void				fdf_fd_error(t_env *e, int fd);
void				fdf_malloc_error(t_env *e);
void				fdf_read_error(t_env *e, char **tmp);
void				fdf_too_many_arg(int argc);

/*
** Hook_FDF
*/

int					mouse_hook(int	button, int	x, int y, t_env *e);
int					key_hook(int	button, t_env *e);

/*
** Colors_FDF
*/

int					set_color(char *s, t_env *e);
unsigned int		conv_c(t_color *color);
t_color				*get_c(t_env *e, t_point *a, double z);
t_color				*init_color(int r, int g, int b);

/*
** Projection_FDF
*/

void				para_projection(t_env *e);
void				isometric_projection(t_env *e);
void				origin_projection(t_env *e);
void				ortho_projection(t_env *e);
void				spher_projection(t_env *e);

/*
** Sphere & Proj_FDF
*/

void				sphere_projection(t_point *p, t_rot *rot);
void				para_proj(t_point *p, t_rot *rot);
void				iso_proj(t_point *p, t_rot *rot);
void				ortho_proj(t_point *p, t_rot *rot);

/*
** Move Rotation_FDF
*/

void				axe_x(t_env *e);
void				axe_y(t_env *e);
void				axe_z(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				rotate_left(t_env *e);
void				rotate_right(t_env *e);

#endif
