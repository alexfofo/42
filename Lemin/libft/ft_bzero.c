/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:14:54 by afollin           #+#    #+#             */
/*   Updated: 2014/03/13 15:16:22 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	if (n <= 0)
		return ;
	while (n > 0)
	{
		b[n - 1] = '\0';
		n--;
	}
}
