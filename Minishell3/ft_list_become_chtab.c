/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_become_chtab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:05:57 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 15:05:58 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell3.h"
#include "libft.h"

int		ft_list_become_chtab(char **line, t_sl **list)
{
	int		i;
	t_sl	*move;

	i = 0;
	move = *list;
	while (move)
	{
		++i;
		move = move->next;
	}
	if (*line)
		free((void *)*line);
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	i = -1;
	move = *list;
	while (move)
	{
		(*line)[++i] = move->c;
		move = move->next;
		free((void *)*list);
		*list = move;
	}
	(*line)[++i] = '\0';
	return (0);
}
