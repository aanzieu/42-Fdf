/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:05:04 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/15 00:39:58 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char*)dest;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		n--;
		temp++;
	}
	return (dest);
}
