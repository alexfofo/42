/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:49:56 by afollin           #+#    #+#             */
/*   Updated: 2014/03/11 17:52:02 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			is_comment(char *line)
{
	if (line == NULL || *line == '\0')
		return (0);
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int			is_number(char *line)
{
	if (*line == '-')
		line++;
	while (*line)
	{
		if (!(ft_isdigit(*line)))
			return (0);
		line++;
	}
	return (1);
}

int			where_is_c_in_str(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int			how_much_c_in_str(char c, char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

char		*ft_get_name(char *line, char c, int i)
{
	char		*ret;
	int			k;
	int			j;

	if (line == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		if (*line == c)
			k++;
		line++;
	}
	k = 0;
	while (line[k] && line[k] != c)
		k++;
	if (k == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (k + 1));
	j = -1;
	while (++j < k)
		ret[j] = line[j];
	ret[j] = '\0';
	return (ret);
}
