/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:17:49 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 14:39:35 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((void *)s);
	}
	while (*s != (char)c)
	{
		s++;
		if (*s == '\0')
			return (NULL);
	}
	return ((void *)s);
}
