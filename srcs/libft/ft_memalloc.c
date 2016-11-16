/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:04:41 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/15 09:14:15 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*alloc;

	if ((alloc = (void*)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(alloc, size);
	return ((void*)alloc);
}
