/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 11:23:02 by afollin           #+#    #+#             */
/*   Updated: 2013/12/19 14:34:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<string.h>
#include		<stdlib.h>
#include		"libft.h"

static int		ft_read(char *buf, int fd, int ret)
{
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

static int		ft_is_new_line(char **line, char *buf, int i)
{
	ft_strncat(*line, buf, i);
	ft_strcpy(buf, ft_strsub(buf, i + 1, BUFF_SIZE - i - 1));
	return (1);
}

static int		ft_no_new_line(char **line, char *buf, int j)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(*tmp) * BUFF_SIZE * j + 1);
	if (tmp == NULL)
		return (-1);
	ft_strclr(tmp);
	ft_strcpy(tmp, *line);
	free((void *)*line);
	j++;
	*line = (char *)malloc(sizeof(**line) * BUFF_SIZE * j + 1);
	if (*line == NULL)
		return (-1);
	ft_strclr(*line);
	ft_strcpy(*line, tmp);
	free((void *)tmp);
	ft_strcat(*line, buf);
	buf[0] = '\0';
	return (j);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	static char	buf[BUFF_SIZE + 1];
	int			i;
	int			j;

	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	ret = 1;
	j = 1;
	while (ret > 0)
	{
		if (buf[0] == '\0')
		{
			if (!(ret = ft_read(buf, fd, ret)) && *line[0] != '\0')
				return (1);
		}
		i = 0;
		while (buf[i] && buf[i] != '\n' && ret > 0)
			i++;
		if (buf[i] == '\n' && ret > 0)
			return (ft_is_new_line(line, buf, i));
		else if (ret > 0 && (j = ft_no_new_line(line, buf, j)) == -1)
			return (-1);
	}
	return (ret);
}
