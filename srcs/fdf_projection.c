/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:39:39 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 09:49:44 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	para_projection(t_env *e)
{
	e->opt = PARA;
	fdf_del(e);
}

void	ortho_projection(t_env *e)
{
	e->opt = ORTHO;
	fdf_del(e);
}

void	spher_projection(t_env *e)
{
	e->opt = SPHERE;
	fdf_del(e);
}

void	isometric_projection(t_env *e)
{
	e->opt = ISO;
	fdf_del(e);
}

void	origin_projection(t_env *e)
{
	e->fovy = 0;
	e->near = 5;
	e->far = 5;
	e->ud = 1;
	e->lr = 1;
	e->opt = ISO;
	fdf_del(e);
}
