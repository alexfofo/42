/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_ter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 16:52:59 by afollin           #+#    #+#             */
/*   Updated: 2015/04/30 16:53:00 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		sigint_handler(int sig_num)
{
	signal(SIGINT, sigint_handler);
	if (sig_num > -2 || sig_num < 0)
		ft_putstr("\n");
}

char		**get_all_words(char *line)
{
	int			i;
	int			nb;
	char		**ret;

	i = -1;
	if ((nb = count_word(line)) == 0)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (nb + 1));
	ret[nb] = NULL;
	while (++i < nb)
		ret[i] = get_word_x(line, i);
	return (ret);
}
