/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment_or_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:49:45 by afollin           #+#    #+#             */
/*   Updated: 2016/03/08 15:49:46 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int			wich_command_is_it(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (21);
	if (!ft_strcmp(line, "##end"))
		return (22);
	return (20);
}

/*
**		return 0 : NOT comment && NOT command
**		return 1 : is COMMENT
**		return 20 : is unknown command
**		return 21 : is start command
**		return 22 : is end command
*/

int			is_comment_or_command(char *line)
{
	if (!ft_strncmp(line, "#", 1))
	{
		if (!ft_strncmp(line, "##", 2))
			return (wich_command_is_it(line));
		return (1);
	}
	return (0);
}
