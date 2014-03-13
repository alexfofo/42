/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:21:32 by afollin           #+#    #+#             */
/*   Updated: 2014/02/09 13:16:04 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	i = -1;
	if (str == NULL)
		return (NULL);
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
