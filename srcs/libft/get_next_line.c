/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:36:35 by aanzieu           #+#    #+#             */
/*   Updated: 2016/11/17 18:54:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		last_line(char **str, char **line)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	free(*str);
	*str = ft_strnew(0);
	return (1);
}

int		one_line(char **str, char **line, int size)
{
	char	*tmp;

	if (!(*line = ft_strsub(*str, 0, size)))
		return (-1);
	tmp = *str;
	if (!(*str = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		return (-1);
	free(tmp);
	tmp = NULL;
	return (1);
}

int		backslach(char *str)
{
	int	x;

	if (!(*str))
		return (-1);
	x = 0;
	while (str[x])
	{
		if (str[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

int		read_line(int fd, char **str, char **line, int size)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if ((size = backslach(*str)) > -1)
			return (one_line(str, line, size));
	}
	return (-42);
}

int		get_next_line(const int fd, char **line)
{
	int				size;
	int				ret;
	static char		*str[MAX_FD];

	size = 0;
	if (fd < 0 || fd >= MAX_FD || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = (char*)ft_memalloc(size + 1);
	if ((size = backslach(str[fd])) > -1)
		return (one_line(&str[fd], line, size));
	if ((ret = read_line(fd, &str[fd], line, size)) != -42)
		return (ret);
	if (ft_strlen(str[fd]) && str[fd] && backslach(str[fd]) == -1)
		return (last_line(&str[fd], line));
	ft_strclr(str[fd]);
	return (0);
}
