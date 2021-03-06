/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:56:13 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 17:02:17 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *s1, char *s2, int ret)
{
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (ret);
}
