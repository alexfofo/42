/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:18:30 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 13:43:09 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (*c1 && *c2 && *c1 == *c2 && n > 0)
	{
		n--;
		if (n == 0)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (*c1 - *c2);
}
