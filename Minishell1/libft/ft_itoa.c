/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:59:01 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 11:01:39 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	size_nb(int n)
{
	size_t		i;

	i = 1;
	while (n > 10 || n < -10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static size_t	ten_power_n_m1(int n)
{
	size_t		i;

	i = 1;
	while (n > 1)
	{
		i = i * 10;
		n--;
	}
	return (i);
}

static char		*str_maloc(int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size_nb(n) + 2))))
		return (NULL);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size_nb(n) + 2);
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	size_t	len;
	long	j;

	j = n;
	len = size_nb(n);
	i = 0;
	str = str_maloc(n);
	if (n < 0)
	{
		str[i] = '-';
		i++;
		if (j < 0)
			j = -j;
	}
	while (len > 0)
	{
		str[i] = j / ten_power_n_m1(len) + '0';
		i++;
		j = j % ten_power_n_m1(len);
		len--;
	}
	return (str);
}
