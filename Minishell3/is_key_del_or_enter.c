/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_del_or_enter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:25:05 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 15:25:07 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_key_enter(char *buf)
{
	if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}

int			ft_is_key_del_right(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
		return (1);
	return (0);
}

int			ft_is_key_del_left(char *buf)
{
	if (buf[0] == 127 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0)
		return (1);
	return (0);
}
