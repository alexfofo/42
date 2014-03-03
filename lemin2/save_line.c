/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:38:02 by afollin           #+#    #+#             */
/*   Updated: 2014/03/03 18:27:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_save_line(int index, char *line)
{
	if (index == 0)
	{
		ft_save_ant(line);
		index++;
	}
	else if (index == 1)
	{
		;
	}
	else if (index == 2)
	{
		;
	}
	return (index);
}
