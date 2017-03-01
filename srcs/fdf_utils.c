/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 08:25:55 by aanzieu           #+#    #+#             */
/*   Updated: 2017/03/01 13:39:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		search_error(char *str)
{
	int i;
	i = 0;
	while(str[i] == '-')
		i++;
	while(str && str[i])
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return(1);
}

int		ft_count_p(void **s)
{
	int count;

	count = 0;
	while(s[count] != NULL)
		count++;
	return(count);
}

int		ft_len_tab(t_env *e)
{
	char buff[BUFF_SIZE + 1];
	int	ret;
	int size;
	int	fd;

	if((fd = open(e->arg, O_RDONLY)) < 0)
	{
		ft_putstr_fd("FD error\n", 2);
		close(fd);
		exit(1);
	}
	size = 0;
	while((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			ft_putstr_fd("READ error\n", 2);
			close(fd);
			exit(1);
		}
		size += ret;
	}
	close(fd);
	return (size);
}
