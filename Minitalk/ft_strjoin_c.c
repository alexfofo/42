/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:54:31 by rcherik           #+#    #+#             */
/*   Updated: 2014/02/08 19:35:15 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin_c(char *s1, char c)
{
	int		d_len;
	char	*temp;

	d_len = ft_strlen(s1);
	temp = ft_strnew(1 + (d_len + 1));
	temp = ft_strcpy(temp, s1);
	temp[d_len] = c;
	return (temp);
}

