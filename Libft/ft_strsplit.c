/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:49:46 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 11:04:24 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**ret_strsplit(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			while (*s != c && *s)
			{
				str[i][j] = *s;
				s++;
				j++;
			}
			str[i][j] = '\0';
		}
		i++;
		while (*s && *s == c)
			s++;
	}
	str[i][0] = '\0';
	return (str);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	return (i);
}

static size_t	ft_wlen(char const *s, char c, size_t index)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s == NULL)
		return (0);
	while (i <= index)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(*str) * (ft_wcount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_wcount(s, c))
	{
		str[i] = (char *)malloc(sizeof(*s) * (ft_wlen(s, c, i) + 1));
		if (str[i] == NULL)
			return (NULL);
		i++;
	}
	str[i] = NULL;
	return (ret_strsplit(s, c, str));
}
