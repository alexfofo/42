/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:47:45 by rcherik           #+#    #+#             */
/*   Updated: 2014/02/09 14:39:28 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		send_msg(int serv_pid, char msg)
{
	char		c;

	c = 0;
	while (c < 8)
	{
		usleep(300);
		if (((msg >> c) & 1) == 1)
			kill(serv_pid, SIGUSR1);
		else
			kill(serv_pid, SIGUSR2);
		c++;
	}
}

static void		client(char **argv)
{
	int		i;
	int		serv_pid;
	char	*s;

	i = 0;
	serv_pid = ft_atoi(argv[1]);
	s = argv[2];
	while (s[i] != '\0')
	{
		send_msg(serv_pid, s[i]);
		i++;
	}
	send_msg(serv_pid, s[i]);
}

static void		get_sig_serv(int sig)
{
	(void)sig;
}

int				main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, get_sig_serv);
		signal(SIGUSR2, get_sig_serv);
		client(argv);
	}
	else
	{
		ft_error("usage: ./client {server PID} {message to display in server}");
		return (1);
	}
	return (0);
}
