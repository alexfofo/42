/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_fast_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:25:18 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 15:25:39 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_key_opt_arrow_left(char *buf)
{
	if ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 68
		&& buf[4] == 0 && buf[5] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
			&& buf[4] == 50 && buf[5] == 68))
		return (1);
	return (0);
}

int			ft_is_key_opt_arrow_right(char *buf)
{
	if ((buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 67
		&& buf[4] == 0 && buf[5] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
			&& buf[4] == 50 && buf[5] == 67))
		return (1);
	return (0);
}

int			ft_is_key_ctrl_a(char *buf)
{
	if ((buf[0] == 1 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && buf[3] == 0))
		return (1);
	return (0);
}

int			ft_is_key_ctrl_e(char *buf)
{
	if ((buf[0] == 5 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && buf[3] == 0))
		return (1);
	return (0);
}
