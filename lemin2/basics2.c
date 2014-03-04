/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:00:20 by afollin           #+#    #+#             */
/*   Updated: 2014/03/04 17:52:52 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

char			*ft_get_room_name(char *line)
{
	int		i;
	char	*ret;

	while (line[i] != ' ')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	ret[i] = '\0';
	while (--i >= 0)
		ret[i] = line[i];
	return (ret);
}

t_room			*ft_new_room(void)
{
	t_room		*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = NULL;
	room->coord_x = -1;
	room->coord_y = -1;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
