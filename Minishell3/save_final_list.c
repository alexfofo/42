/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_final_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:26:14 by afollin           #+#    #+#             */
/*   Updated: 2014/03/13 15:49:30 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "ft_minishell3.h"
#include "libft.h"

static int	ft_little_move(char *buf, t_sl **list, int *cursor, int co)
{
	int			len;

	len = ft_slist_len(*list);
	if (KEY_OPT_ARROW_UP(buf) && (P_LEN + *cursor) >= co)
	{
		*cursor -= co;
		if (*cursor < 0)
			*cursor = 0;
	}
	else if (KEY_OPT_ARROW_DOWN(buf)
				&& ((P_LEN + *cursor) / co) < ((P_LEN + len) / co))
	{
		if (len - *cursor > co)
			*cursor += co;
		else
			*cursor = len;
	}
	else if (*cursor > 0 && KEY_ARROW_LEFT(buf))
		--(*cursor);
	else if (*cursor < len && KEY_ARROW_RIGHT(buf))
		++(*cursor);
	else
		return (1);
	return (0);
}

int			ft_put_or_del_char(char *buf, t_sl **list, t_save *save, t_hl **hl)
{
	if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], list, save->cursor) == -1)
			return (-1);
		++(save->cursor);
	}
	else if (save->cursor > 0 && KEY_DEL_LEFT(buf))
	{
		--(save->cursor);
		ft_list_del_elem(list, save->cursor);
	}
	else if (save->cursor < ft_slist_len(*list) && KEY_DEL_RIGHT(buf))
		ft_list_del_elem(list, save->cursor);
	else
		return (1);
	if (save->hist_nb)
	{
		save->hist_nb = 0;
		while ((*hl)->prev)
			*hl = (*hl)->prev;
	}
	return (0);
}

static int	ft_check(char *buf, t_sl **l, t_save *save, t_hl **hlist)
{
	struct winsize		w;
	int					old_line;
	int					i;

	i = -1;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	save->co = w.ws_col;
	old_line = (P_LEN + save->cursor) / save->co;
	if (KEY_ENTER(buf))
	{
		save->cursor = ft_slist_len(*l);
		ft_print(*l, save, old_line);
		save->cursor = -1;
		return (0);
	}
	if (i && (i = ft_little_move(buf, l, &(save->cursor), save->co)) == -1)
		return (-1);
	if (i && (i = ft_fast_move(buf, l, &(save->cursor), save->co)) == -1)
		return (-1);
	if ((i && (i = ft_historic(buf, l, save, hlist)) == -1)
			|| (i && (i = ft_put_or_del_char(buf, l, save, hlist)) == -1)
			|| (i && (i = ft_cut_copy_or_paste(buf, l, save)) == -1))
		return (-1);
	ft_print(*l, save, old_line);
	return (0);
}

static void	ft_init_struct(t_save *save, t_hl **hlist)
{
	save->cursor = 0;
	save->hist_nb = 0;
	save->copy = NULL;
	save->hlen = ft_hlist_len(*hlist);
}

int			ft_save_final_list(t_hl **hlist, char **line)
{
	int				n;
	char			buf[MAX_KEY_LEN + 1];
	t_save			save;
	t_sl			*list;

	ft_init_struct(&save, hlist);
	list = NULL;
	ft_putstr("_$> ");
	while (save.cursor != -1)
	{
		n = -1;
		while (++n <= MAX_KEY_LEN)
			buf[n] = 0;
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		if (ft_check(buf, &list, &save, hlist) == -1)
			return (-1);
	}
	if (ft_in_history(hlist, &list) == -1)
		return (-1);
	ft_list_become_chtab(line, &list);
	ft_putchar('\n');
	return (0);
}
