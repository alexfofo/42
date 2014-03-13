/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:03:08 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 17:45:21 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_minishell3.h"

static void		ft_slist_print(t_sl *list, int co)
{
	int		i;

	i = P_LEN;
	while (list)
	{
		ft_putchar_fd(list->c, 2);
		list = list->next;
		++i;
		if (i % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
}

static int		ft_clean(int old_line, int cursor_line)
{
	int		i;

	i = old_line;
	while (i < cursor_line)
	{
		tputs(tgetstr("do", NULL), 1, ft_putc);
		++i;
	}
	while (i > cursor_line)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		--i;
	}
	return (0);
}

int				ft_print(t_sl *list, t_save *save, int old_line)
{
	int		cursor_line;
	int		i;
	char	*tgo;

	cursor_line = (P_LEN + save->cursor) / save->co;
	if (list)
		ft_clean(old_line, cursor_line);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_putc);
	i = cursor_line + 1;
	while (list && (--i > 0))
		tputs(tgetstr("up", NULL), 1, ft_putc);
	tputs(tgetstr("cd", NULL), 1, ft_putc);
	ft_putstr("_$> ");
	ft_slist_print(list, save->co);
	if (list && (save->cursor != ft_slist_len(list)))
	{
		tgo = tgoto(tgetstr("ch", NULL), 0, (P_LEN + save->cursor) % save->co);
		tputs(tgo, 1, ft_putc);
		i = ((P_LEN + ft_slist_len(list)) / save->co) + 1;
		while (--i > cursor_line)
			tputs(tgetstr("up", NULL), 1, ft_putc);
	}
	return (0);
}
