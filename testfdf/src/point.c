/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:09:26 by aanzieu           #+#    #+#             */
/*   Updated: 2017/02/20 16:22:39 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void	new_point(int x, int y, double z, t_env *e)
{
	t_m3	*p;
	t_m3	*goy;

	p = new_m3(x, y, z, 0);
	goy = e->p;
	if (goy == NULL)
	{
		e->p = p;
		return ;
	}
	while (goy->next != NULL)
		goy = goy->next;
	goy->next = p;
}

void	end_point(t_env *e)
{
	t_m3	*p;

	p = e->p;
	while (p->next != NULL)
		p = p->next;
	p->end = 1;
}

t_m3	*new_m3(int x, int y, int z, char end)
{
	t_m3	*p;

	p = (t_m3 *)malloc(sizeof(t_m3));
	p->x = x;
	p->y = y;
	p->z = z;
	p->end = end;
	p->next = NULL;
	return (p);
}
