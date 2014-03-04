/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:43:39 by afollin           #+#    #+#             */
/*   Updated: 2014/03/04 18:26:02 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int			ft_check_line(int index, char *line)
{
	if (index == 0)
	{
		if (!(is_number(line)) || *line == '0')
		{
			ft_putstr_fd("Error about the number of ant\n", 2);
			exit(0);
		}
		return (0);
	}
	if (index == 1)
		index = ft_check_coords(index, line);
	if (index == 2)
		index = ft_check_links(line);
	return (index);
}

int			ft_check_coords(int index, char *line)
{
	static int		start = 0;
	static int		end = 0;

	if (*line == '#' && *(line + 1) == '#')
	{
		if (!(ft_strncmp((line + 2), "start", 5)) && start < 1)
			start++;
		else if (!(ft_strncmp((line + 2), "end", 3)) && end < 1)
			end++;
		else
		{
			ft_putstr_fd("bad coord: ", 2);
			ft_putendl_fd(line, 2);
			return (-5);
		}
		return (-index);
	}
	if (how_much_c_in_str('-', line) > 0)
		return (index + 1);
	if (how_much_c_in_str(' ', line) != 2)
	{
		ft_putstr_fd("nop, wrong syntaxe for this coord", 2);
		ft_putendl_fd(line, 2);
		return (-5);
	}
	while (*line != ' ')
		line++;
	line++;
	if (!(ft_isdigit(*line)))
	{
		ft_putstr_fd("il manque quelque chose, e.g. un chiffre", 2);
		return (-5);
	}
	while (ft_isdigit(*line))
		line++;
	line++;
	if (!(ft_isdigit(*line)))
	{
		ft_putstr_fd("il manque quelque chose, e.g. un chiffre", 2);
		return (-5);
	}
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (-5);
	return (index);
}

int			ft_check_links(char *line)
{
	if (!(ft_strncmp(line, "END", 3)))
		return (-4);
	if (how_much_c_in_str('-', line) != 1)
	{
		ft_putstr_fd("wrong line: ", 2);
		ft_putendl_fd(line, 2);
		return (-5);
	}
	if (how_much_c_in_str(' ', line) != 0)
	{
		ft_putendl_fd("please no spaces 0.0", 2);
		return (-5);
	}
	return (2);
}
