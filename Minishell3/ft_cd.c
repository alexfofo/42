/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 15:13:24 by afollin           #+#    #+#             */
/*   Updated: 2014/02/06 18:16:43 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_minishell3.h"

void		ft_cd(const char *path, char *line, char **env)
{
	int				i;
	char			**split;
	char			*home;

	split = ft_strsplit(line, ' ');
	if (!(split[1]))
	{
		home = search_in_env(env, "HOME=");
		if (home == NULL)
			ft_putendl_fd("No var HOME in environment, i stay here", 2);
		else if (chdir(home + 5) != 0)
		{
			ft_putstr_fd("Impossible to access to:     ", 2);
			ft_putendl_fd(home, 2);
		}
		return ;
	}
	i = chdir(path);
	if (i < 0)
	{
		ft_putstr("cd: no such directory or no permission to get into it: ");
		ft_putendl(line + 3);
	}
}

char		*search_in_env(char **env, char *var)
{
	while (*env && **env)
	{
		if (ft_strncmp(var, *env, ft_strlen(var)) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}
