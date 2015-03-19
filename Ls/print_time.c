/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:12:14 by afollin           #+#    #+#             */
/*   Updated: 2015/03/19 14:12:15 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static char		*get_far_time(time_t *t)
{
	char		*tmp;
	int			i;
	char		*ret;

	i = -1;
	tmp = ctime(t);
	while (*tmp != ' ')
		++tmp;
	++tmp;
	while (tmp[++i] != ' ')
		;
	++i;
	while (tmp[++i] != ' ')
		;
	++i;
	tmp[i] = tmp[i + 9];
	tmp[i + 1] = tmp[i + 9 + 1];
	tmp[i + 2] = tmp[i + 9 + 2];
	tmp[i + 3] = tmp[i + 9 + 3];
	tmp[i + 4] = '\0';
	ret = duplicate_str(tmp);
	return (ret);
}

static char		*get_close_time(time_t *t)
{
	char		*tmp;
	char		*ret;
	int			i;

	i = -1;
	tmp = ctime(t);
	while (*tmp != ' ')
		++tmp;
	++tmp;
	while (tmp[++i] != ' ')
		;
	++i;
	while (tmp[++i] != ' ')
		;
	++i;
	tmp[i + 5] = '\0';
	ret = duplicate_str(tmp);
	return (ret);
}

void			print_last_modif_time(time_t mtime)
{
	time_t		cur_time;
	struct tm	*time_info;
	char		*ret;

	time(&cur_time);
	if ((mtime + 15778463) < cur_time || (mtime - 3600) > cur_time)
		ret = get_far_time(&mtime);
	else
		ret = get_close_time(&mtime);
	ft_putstr(ret);
	return ;
}
