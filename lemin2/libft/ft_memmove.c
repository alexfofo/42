/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:54:59 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 14:43:27 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (c2 < c1)
	{
		c1 = c1 + n - 1;
		c2 = c2 + n - 1;
		while (n--)
		{
			*c1 = *c2;
			c1--;
			c2--;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
