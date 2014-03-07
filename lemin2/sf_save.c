/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:51:52 by afollin           #+#    #+#             */
/*   Updated: 2014/03/07 14:26:56 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

int				set_start_end(t_game *game)
{
	if (game->i_start)
	{
		game->start = game->room->name;
		game->i_start = 0;
	}
	if (game->i_end)
	{
		game->end = game->room->name;
		game->i_end = 0;
	}
	return (0);
}
