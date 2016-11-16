/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:55 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/15 09:19:06 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	j;

	j = 0;
	if (ft_strlen(s) < start || !s)
		return (NULL);
	if (!(new = (char*)malloc(len + 1)))
		return (NULL);
	while (j < len && s[start])
		new[j++] = s[start++];
	new[j] = '\0';
	return (new);
}
