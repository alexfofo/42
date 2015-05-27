/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:59:09 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 14:43:54 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > ft_strlen(dst))
	{
		i = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
	}
	else
	{
		i = size + ft_strlen(src);
	}
	return (i);
}
