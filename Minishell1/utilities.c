/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:23:28 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:23:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			count_word(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '	')
			++i;
		while (str[i] && str[i] != ' ' && str[i] != '	')
		{
			++i;
			if (!str[i] || str[i] == ' ' || str[i] == '	')
				++count;
		}
	}
	return (count);
}

int			additionnal_gwx(char *str, int x, int *i)
{
	int		count;

	count = 0;
	while (str[*i] && count < x)
	{
		while (str[*i] == ' ' || str[*i] == '	')
			++(*i);
		while (str[*i] && str[*i] != ' ' && str[*i] != '	')
		{
			++(*i);
			if (!str[*i] || str[*i] == ' ' || str[*i] == '	')
				++count;
		}
	}
	return (count);
}

char		*get_word_x(char *str, int x)
{
	char		*ret;
	int			i;
	int			j;
	int			count;

	ret = NULL;
	i = 0;
	count = additionnal_gwx(str, x, &i);
	while (str[i] == ' ' || str[i] == '	')
		++i;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '	')
		++j;
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	ft_bzero(ret, j - i + 1);
	count = -1;
	while (++count < j - i)
		ret[count] = str[i + count];
	return (ret);
}

int			additionnal_gwx_spe(char *str, int x, char c, int *i)
{
	int		count;

	count = 0;
	while (str[*i] && count < x)
	{
		while (str[*i] == c)
			++(*i);
		while (str[*i] && str[*i] != c)
		{
			++(*i);
			if (!str[*i] || str[*i] == c)
				++count;
		}
	}
	return (count);
}

char		*get_word_x_spe(char *str, int x, char c)
{
	char		*ret;
	int			i;
	int			j;
	int			count;

	ret = NULL;
	i = 0;
	count = additionnal_gwx_spe(str, x, c, &i);
	if (!str[i] && count < x)
		return (NULL);
	while (str[i] == c)
		++i;
	j = i;
	while (str[j] && str[j] != c)
		++j;
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	ft_bzero(ret, j - i + 1);
	count = -1;
	while (++count < j - i)
		ret[count] = str[i + count];
	return (ret);
}
