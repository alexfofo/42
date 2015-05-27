/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:59:24 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 14:09:25 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	if (s == NULL)
		return (NULL);
	a = (unsigned char *)s;
	while (n-- && *a)
	{
		if (*a != (unsigned char)c)
			a++;
		else
			return (a);
	}
	if ((unsigned char)c == *a)
		return (a);
	return (NULL);
}
