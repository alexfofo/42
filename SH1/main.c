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

char		*handle_tild(char *home_env, char *line)
{
	char	*ret;
	int		len_hv;
	int		len_line;
	int		flag;

	if (!home_env || ft_strlen(home_env) < 5)
		return (line);
	home_env += 5;
	flag = 0;
	len_hv = ft_strlen(home_env);
	len_line = ft_strlen(line);
	ret = line - 1;
	while (*(++ret))
		flag = (*ret == '~' ? 1 : flag);
	if (flag == 0)
		return (line);
	ret = (char *)malloc(sizeof(char) * (len_hv + len_line));
	flag = -1;
	while (line[++flag] != '~')
		ret[flag] = line[flag];
	ft_strcat(ret, home_env);
	while (line[++flag])
		ret[flag - 1 + len_hv] = line[flag];
	free(line);
	return (ret);
}

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
		line = handle_tild(get_env_var(env, "HOME"), line);
		cp_env = env_stuff(line, &cute_flag, cp_env);
		cp_env = cd_stuff(line, &cute_flag, cp_env);
		execute_stuff(ft_strsplit(line, ' '), &cute_flag, cp_env);
		unknown_cmd(line, cute_flag);
		cute_flag = 0;
	}
	return (0);
}
