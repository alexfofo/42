/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:43:39 by afollin           #+#    #+#             */
/*   Updated: 2014/03/03 18:27:30 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_check_line(int index, char *line)
{
	if (index == 0)
	{
		if (!(is_number(line)))
		{
			ft_putstr_fd("Error about the number of ant");
			exit(0);
		}
		return (0);
	}
	else if (index == 1)
	{
		index = ft_check_coords(index, line);
	}
	else if (index == 2)
	{
		ft_check_links(line);
	}
	return (-5);
}

int			ft_check_coords(int index, char *line)
{
	static int		start = 0;
	static int		end = 0;


	return (index);
}
