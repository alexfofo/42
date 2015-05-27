/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:26:20 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:26:21 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "sh.h"

int			is_dir(char *entity_path)
{
	struct stat		st;

	if (lstat(entity_path, &st) == -1)
		return (-1);
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

int			ft_find(char c, char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

char		*find_exec_path(char *env_path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while ((tmp = get_word_x_spe(env_path, ++i, ':')) != NULL)
	{
		tmp2 = ft_strcat_in_new_str(tmp, "/");
		free(tmp);
		tmp = ft_strcat_in_new_str(tmp2, cmd);
		free(tmp2);
		if (access(tmp, F_OK) != -1 && access(tmp, X_OK) != -1 && !is_dir(tmp))
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

void		do_exec(char *path_to_exec, char **tab_str, char **env, int *f)
{
	pid_t	father;
	int		child_status;

	father = fork();
	if (father > 0)
		wait(&child_status);
	if (father == 0)
	{
		if (execve(path_to_exec, tab_str, env) == -1)
			exit(1);
	}
	*f = 1;
	return ;
}

void		execute_stuff(char **tab_str, int *f, char **env)
{
	char	*path_to_exec;
	int		i;

	if (!tab_str || !(tab_str[0]))
		return ;
	i = -1;
	path_to_exec = NULL;
	if (*f)
		return ;
	while (env[++i] && cmp_spe(env[i], "PATH", '='))
		;
	if (!env[i])
		return ;
	path_to_exec = find_exec_path(env[i] + 5, tab_str[0]);
	if (path_to_exec != NULL)
	{
		do_exec(path_to_exec, tab_str, env, f);
		free(path_to_exec);
	}
	else if (ft_find('/', tab_str[0]) && !is_dir(tab_str[0]))
	{
		if (access(tab_str[0], F_OK) != -1 && access(tab_str[0], X_OK) != -1)
			do_exec(tab_str[0], tab_str, env, f);
	}
	return ;
}
