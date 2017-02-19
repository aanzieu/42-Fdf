/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 12:04:33 by adespond          #+#    #+#             */
/*   Updated: 2016/03/08 12:04:35 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	new_point(int x, int y, double z, t_env *e)
{
	t_m3	*p;
	t_m3	*next;

	p = new_m3(x, y, z, 0);
	next = e->p;
	if (next == NULL)
	{
		e->p = p;
		return ;
	}
	while (next->next != NULL)
		next = next->next;
	next->next = p;
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
