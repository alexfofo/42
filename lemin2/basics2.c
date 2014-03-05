/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:00:20 by afollin           #+#    #+#             */
/*   Updated: 2014/03/05 14:50:59 by afollin          ###   ########.fr       */
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

/*
** Cette fonction est a bouger dans sf_check
*/
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

char			*ft_get_name(char *line, char c, int i)
{
	char		*ret;
	int			k;
	int			j;

	if (line == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		if (*line == c)
			k++;
		line++;
	}
	k = 0;
	while (line[k] && line[k] != c)
		k++;
	if (k == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (k + 1));
	j = -1;
	while (++j < k)
		ret[j] = line[j];
	ret[j] = '\0';
	return (ret);
}

int				ft_is_str_a_room(char *str, t_room *room)
{
	while (room)
	{
		if (!(ft_strcmp(room->name, str)))
			return (1);
		room = room->next;
	}
	return (0);
}
