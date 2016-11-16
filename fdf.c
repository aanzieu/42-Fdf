/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:38:00 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/16 12:11:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static char		fdf_read(t_env *env, char *argv)
{
	t_fdf	fdf;

	if((env->fd = open(argv, O_RDONLY)) < 0)
		return(env->line == NULL);
	while(get_next_line(env->fd, env->line))
		{
			fdf.ft_strsplit(env->line, ' ');
}

int		main(int argc, char **argv)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 400, 400, "42 FDF");
	fdf_read(env, argv[1]);
//	drag_drop(&env);

	return (0);
}
