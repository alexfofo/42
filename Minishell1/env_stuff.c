/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:27:01 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:27:02 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		**do_setenv(char *line, char **env)
{
	int		i;
	char	*keyword;
	char	*value;
	char	**ret;

	i = -1;
	if (count_word(line) != 3)
	{
		ft_putendl_fd("usage: setenv {keyword} {value}", 2);
		return (env);
	}
	keyword = get_word_x(line, 1);
	value = get_word_x(line, 2);
	ret = add_to_env(env, keyword, value);
	free(keyword);
	free(value);
	return (ret);
}

char		**do_unsetenv(char *line, char **env)
{
	char	*keyword;

	if (count_word(line) != 2)
	{
		ft_putendl_fd("usage: unsetenv {keyword}", 2);
		return (env);
	}
	keyword = get_word_x(line, 1);
	env = remove_from_env(env, keyword);
	free(keyword);
	return (env);
}

char		**env_stuff(char *line, int *f, char **env)
{
	char	*tmp;

	if (*f)
		return (env);
	tmp = get_word_x(line, 0);
	if (!ft_strcmp(tmp, "env"))
	{
		print_tab_str(env);
		*f = 1;
	}
	else if (!ft_strcmp(tmp, "setenv"))
	{
		env = do_setenv(line, env);
		*f = 1;
	}
	else if (!ft_strcmp(tmp, "unsetenv"))
	{
		env = do_unsetenv(line, env);
		*f = 1;
	}
	free(tmp);
	return (env);
}

char		*get_env_var(char **env, char *var)
{
	int		i;

	i = -1;
	while (env[++i] && env[i][0])
	{
		if (!cmp_spe(env[i], var, '='))
			return (env[i]);
	}
	return (NULL);
}
