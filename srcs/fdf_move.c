/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:30:29 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/03 09:48:46 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_left(t_env *e)
{
	e->lr -= 10;
	fdf_del(e);
}

void	move_right(t_env *e)
{
	e->lr += 10;
	fdf_del(e);
}

void	rotate_left(t_env *e)
{
	e->fovy += 0.05;
	fdf_del(e);
}

void	rotate_right(t_env *e)
{
	e->fovy -= 0.05;
	fdf_del(e);
}
