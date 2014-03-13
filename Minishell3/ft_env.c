/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:13:52 by afollin           #+#    #+#             */
/*   Updated: 2014/02/06 18:16:54 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

void		ft_env(char **env)
{
	while (*env && **env)
	{
		ft_putendl(*env);
		env++;
	}
}

void		ft_unsetenv(char *line, char **env)
{
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (!(tmp[1]))
	{
		ft_putstr("not enough arguments, usage: unsetenv [variable]\n");
		return ;
	}
	while (*env && **env)
	{
		if (ft_strncmp(tmp[1], *env, ft_strlen(tmp[1])) == 0)
		{
			while (*(env + 1) && **(env + 1))
			{
				*env = (char *)malloc(sizeof(char) * ft_strlen(*(env + 1)));
				ft_strcpy(*env, *(env + 1));
				env++;
			}
			*env = '\0';
		}
		env++;
	}
}

void		ft_setenv(char *line, char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (ft_error_setenv(tmp) == 1)
		return ;
	while (*env && **env)
	{
		if (ft_strncmp(tmp[1], *env, ft_strlen(tmp[1])) == 0)
		{
			i = 1;
			if (tmp[3] && ft_strcmp(tmp[3], "0") == 0)
				return ;
			break ;
		}
		env++;
	}
	*env = (char *)malloc(sizeof(char) * ft_strlen(line));
	ft_cat_setenv(env, tmp);
	free(tmp);
	if (i == 1)
		return ;
	*(env + 1) = '\0';
}

void		ft_cat_setenv(char **env, char **tmp)
{
	ft_strcpy(*env, tmp[1]);
	ft_strcat(*env, "=");
	ft_strcat(*env, tmp[2]);
}

int			ft_error_setenv(char **tmp)
{
	if (!tmp[1] || !tmp[2])
	{
		ft_putstr("not enough arguments, go read man 3 setenv\n");
		return (1);
	}
	return (0);
}
