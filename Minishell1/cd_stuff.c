/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:26:09 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:26:10 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		**additionnal_cs(char *line, char **env, char *word_1, int *f)
{
	int		ret;
	char	buf[256];
	char	*word_2;

	ret = -1;
	word_2 = get_word_x(line, 1);
	getcwd(buf, 256);
	if (count_word(line) == 1)
		ret = chdir(get_env_var(env, "HOME") + 5);
	else if (!ft_strcmp(word_2, "-"))
		ret = chdir(get_env_var(env, "OLDPWD") + 7);
	else
		ret = chdir(word_2);
	if (ret == -1)
		ft_putendl_fd("Impossible de changer de repertoire.", 2);
	else
	{
		env = add_to_env(env, "OLDPWD", buf);
		getcwd(buf, 256);
		env = add_to_env(env, "PWD", buf);
	}
	free(word_1);
	free(word_2);
	*f = 1;
	return (env);
}

char		**cd_stuff(char *line, int *f, char **env)
{
	char	*word_1;

	if (*f)
		return (env);
	word_1 = get_word_x(line, 0);
	if (ft_strcmp(word_1, "cd"))
	{
		free(word_1);
		return (env);
	}
	if (count_word(line) > 2)
	{
		ft_putendl_fd("usage: cd {directory}", 2);
		free(word_1);
		return (env);
	}
	env = additionnal_cs(line, env, word_1, f);
	return (env);
}
