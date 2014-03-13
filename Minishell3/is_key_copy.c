/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:24:33 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 15:24:36 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_key_ctrl_u(char *buf)
{
	if (buf[0] == 21 && buf[1] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_i(char *buf)
{
	if (buf[0] == 9 && buf[1] == 0)
		return (1);
	return (0);
}

int			ft_is_key_ctrl_h(char *buf)
{
	if (buf[0] == 8 && buf[1] == 0)
		return (1);
	return (0);
}
