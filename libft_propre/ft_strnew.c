/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:21:32 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 14:48:53 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	str[i] = '\0';
	return (str);
}
