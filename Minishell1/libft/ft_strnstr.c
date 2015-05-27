/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:28:29 by afollin           #+#    #+#             */
/*   Updated: 2015/04/22 16:37:16 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	l = ft_strlen(s2);
	if (*s2 == '\0')
	{
		return ((void *)s1);
	}
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
			if (j == l)
				return ((void *)&s1[i - j]);
			if (j == n)
				return (NULL);
		}
		i = i - j + 1;
	}
	return (NULL);
}
