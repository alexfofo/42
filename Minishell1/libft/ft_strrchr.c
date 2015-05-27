/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:53:49 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 14:40:01 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((void *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			i = 1;
		s++;
	}
	if (i == 0)
		return (NULL);
	while (*s != (char)c)
	{
		s--;
	}
	return ((void *)s);
}
