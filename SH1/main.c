/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:22:52 by afollin           #+#    #+#             */
/*   Updated: 2015/04/22 18:11:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		early_exit(int argc, char **argv)
{
	int		i;

	i = -1;
	argc = 0;
	ft_putstr_fd("usage: ", 2);
	ft_putendl_fd(argv[0], 2);
	exit(0);
	return ;
}

int			go_gnl(int i, char **line)
{
	ft_putstr("\033[1;37m#$^&\033[0;31m42\033[1;37m*>> \033[0m");
	return (get_next_line(i, line));
}

void		unknown_cmd(char *line, int f)
{
	if (ft_strcmp(line, "42") == 0)
		ft_putendl_fd("RPZ ma ptite gueule", 1);
	else if (f == 0)
		ft_putendl_fd("Unknown command", 2);
	return ;
}

int			main(int argc, char **argv, char **env)
{
	char		**cp_env;
	char		*line;
	int			cute_flag;

	if (argc != 1)
		early_exit(argc, argv);
	cp_env = cp_tab_str(env);
	cute_flag = 0;
	while (go_gnl(0, &line) > 0)
	{
		if (!line || !line[0])
			continue ;
		if (ft_strcmp(line, "exit") == 0)
			return (1);
		cp_env = env_stuff(line, &cute_flag, cp_env);
		cp_env = cd_stuff(line, &cute_flag, cp_env);
		execute_stuff(ft_strsplit(line, ' '), &cute_flag, cp_env);
		unknown_cmd(line, cute_flag);
		cute_flag = 0;
	}
	return (0);
}
