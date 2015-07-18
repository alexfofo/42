/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:44:51 by afollin           #+#    #+#             */
/*   Updated: 2014/03/13 15:55:36 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		ft_end(char **ret)
{
	ft_putstr(*ret);
	write(1, "\n", 1);
	if (ft_strcmp(*ret, "exit") == 0)
	{
		free(*ret);
		*ret = NULL;
		exit(0);
	}
	free(*ret);
	*ret = NULL;
}

static void		get_sig(int sig)
{
	static char		c = 0;
	static int		i = 0;
	static char		*ret = NULL;

	if (ret == NULL)
		ret = ft_strnew(1);
	if (sig == SIGUSR1)
		c |= (1 << i++);
	else if (sig == SIGUSR2)
		c |= (0 << i++);
	if (i > 7)
	{
		ret = ft_strjoin_c(ret, c);
		if (c == 0)
			ft_end(&ret);
		c = 0;
		i = 0;
	}
}

static void		sigs(void)
{
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
}

int				main(void)
{
	sigs();
	ft_putswag("Server PID: ");
	write(1, "\033[33m", 5);
	ft_putnbr(getpid());
	write(1, "\033[0m", 4);
	ft_putswag("\n");
	while (42)
		pause();
	return (0);
}
