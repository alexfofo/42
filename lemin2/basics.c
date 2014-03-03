/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:49:56 by afollin           #+#    #+#             */
/*   Updated: 2014/03/03 18:42:55 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int			is_number(char *line)
{
	while (*line)
	{
		if (!(ft_isdigit(*line)))
			return (0);
		line++;
	}
	return (1);
}

int			c_is_in_str(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}
