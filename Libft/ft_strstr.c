/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:57:07 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 15:22:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	l = ft_strlen(s2);
	if (*s2 == '\0')
	{
		return (s1);
	}
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (j == l)
				return (&s1[i - j]);
		}
		i = i - j + 1;
	}
	return ('\0');
}
