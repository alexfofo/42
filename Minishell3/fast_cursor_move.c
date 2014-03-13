/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cursor_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:03:30 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:30:08 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <string.h>
#include <term.h>
#include "libft.h"
#include "ft_minishell3.h"

static void		ft_go_to_prev_word(t_sl **list, int *cursor, int co)
{
	int		i;
	t_sl	*move;

	co += 1;
	co -= 1;
	move = *list;
	if (*cursor > 0)
		--(*cursor);
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor > 0 && move && move->prev
			&& !(move->c != ' ' && (move->prev)->c == ' '))
	{
		--(*cursor);
		move = move->prev;
	}
}

static void		ft_go_to_next_word(t_sl **list, int *cursor, int co)
{
	int		i;
	t_sl	*move;
	int		len;

	co += 1;
	co -= 1;
	len = ft_slist_len(*list);
	move = *list;
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor < len && move && move->next
			&& !(move->c == ' ' && (move->next)->c != ' '))
	{
		move = move->next;
		++(*cursor);
	}
	if (*cursor < len)
		++(*cursor);
}

int				ft_fast_move(char *buf, t_sl **list, int *cursor, int co)
{
	if (*cursor > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(list, cursor, co);
	else if (*cursor < ft_slist_len(*list) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(list, cursor, co);
	else if (KEY_CTRL_A(buf))
		*cursor = 0;
	else if (KEY_CTRL_E(buf))
		*cursor = ft_slist_len(*list);
	else
		return (1);
	return (0);
}
