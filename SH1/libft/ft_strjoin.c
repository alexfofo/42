/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:37:57 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 11:03:43 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*str_maloc1(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = str_maloc1(s1, s2);
	while (*s1 || *s2)
	{
		if (*s1)
		{
			str[i] = *s1;
			i++;
			s1++;
		}
		else
		{
			str[i] = *s2;
			i++;
			s2++;
		}
	}
	str[i] = '\0';
	return (str);
}
