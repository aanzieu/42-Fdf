/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:13:47 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/16 10:31:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     my_getnbr(char *str, char base)
{
	int   i;
	int   nbr;
	int		neg;

	nbr = 0;
	i = 0;
	neg = 1
	while (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str && ft_isdigit(str[i]))
	{
		nbr = ((nbr * 10) + (str[i] - 48));
		i++;
	}
	return (neg * nbr);
}
