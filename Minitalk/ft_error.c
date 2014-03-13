/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:14:17 by rcherik           #+#    #+#             */
/*   Updated: 2014/01/31 17:27:26 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		ft_error(char *s)
{
	write(2, "\033[31m", 5);
	write(2, s, ft_strlen(s));
	write(2, "\n\033[0m", 5);
}
