/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:07:00 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 14:36:38 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*zmem;

	if (s == NULL)
		return (NULL);
	zmem = (char *)malloc(sizeof(*s) * (len + 1));
	if (zmem == NULL)
		return (NULL);
	ft_strncpy(zmem, (s + start), len);
	return ((char *)zmem);
}
