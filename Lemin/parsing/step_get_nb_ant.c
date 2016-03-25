/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_get_nb_ant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:00:33 by afollin           #+#    #+#             */
/*   Updated: 2016/03/10 18:00:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

int		step_get_nb_ant(char *line, t_resources *resources)
{
	int		nb_ant;
	char	*nb_ant_str;

	nb_ant = ft_atoi(line);
	nb_ant_str = ft_itoa(nb_ant);
	if (is_comment_or_command(line))
		return (0);
	if (ft_strcmp(line, nb_ant_str) || nb_ant <= 0)
	{
		free(nb_ant_str);
		return (-1);
	}
	free(nb_ant_str);
	resources->nb_ant = nb_ant;
	return (1);
}
