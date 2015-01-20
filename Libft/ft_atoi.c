/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:02:12 by afollin           #+#    #+#             */
/*   Updated: 2015/01/20 11:01:06 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		get_to_begining(char *str)
{
	int		j;

	j = 0;
	while ((str[j] == ' ' || str[j] == '\n' || str[j] == '\v' || str[j] == '\t'
			|| str[j] == '\r' || str[j] == '\f' || str[j] == '+') && str[j])
		j++;
	return (j);
}

int				ft_atoi(char *str)
{
	int		i;
	int		j;
	int		neg;

	i = 0;
	neg = 1;
	if (str == NULL)
		return (0);
	j = get_to_begining(str);
	if (str[j] == '-')
	{
		neg = -1;
		j++;
	}
	if ((str[j - 1] == '-' || str[j - 1] == '+') && (str[j - 2] == '-'
				|| str[j - 2] == '+'))
		return (0);
	while (str[j] && (str[j] >= '0' && str[j] <= '9'))
	{
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i * neg);
}
