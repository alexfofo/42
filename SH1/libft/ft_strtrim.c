/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:40:24 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 11:05:02 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		white_space_catch_zero(const char *s, char *str, int i)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
	{
		str[i] = '\0';
		return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s)
	{
		str[i] = *s;
		i++;
		s++;
		if (*s == ' ' || *s == '\n' || *s == '\t')
		{
			if (white_space_catch_zero(s, str, i) == 1)
				break ;
		}
	}
	str[i] = '\0';
	return (str);
}
