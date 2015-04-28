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

// #include "libft.h"
#include "sh.h"

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
		if (access(tmp, F_OK) != -1)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

void		do_exec(char *path_to_exec, char **tab_str, char **env)
{
	pid_t	father;
	int		child_status;

	father = fork();
	if (father > 0)
		wait(&child_status);
	if (father == 0)
		execve(path_to_exec, tab_str, env);
	return ;
}

void		execute_stuff(char **tab_str, int *f, char **env)
{
	char	*path_to_exec;
	int		i;

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
		*f = 1;
		do_exec(path_to_exec, tab_str, env);
	}
	return ;
}