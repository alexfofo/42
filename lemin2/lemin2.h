/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:27:50 by afollin           #+#    #+#             */
/*   Updated: 2014/03/03 15:39:04 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN2_H
# define LEMIN2_H

# include "lemin2.h"
# include "libft.h"

typedef struct		s_link
{

}

typedef struct		s_game
{
	int				nb_ant;
	char			*start;
	char			*end;
	t_coord			*coord;
	t_link			*link;
}					t_game;

#endif /* !LEMLIN2_H */
