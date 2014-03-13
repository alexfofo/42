/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:01:57 by rcherik           #+#    #+#             */
/*   Updated: 2014/02/08 17:02:04 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*t_dest;
	const char	*t_src;

	t_dest = dst;
	t_src = src;
	while (n--)
		*t_dest++ = *t_src++;
	return (dst);
}
