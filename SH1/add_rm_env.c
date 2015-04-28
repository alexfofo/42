/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:21:50 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:21:51 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "sh.h"

char		**additionnal_ate_1(int *count, char **tab)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 2);
	ret[1] = NULL;
	*count = 0;
	if (tab != NULL)
		free(tab);
	return (ret);
}

char		**additionnal_ate_2(char **tab, char *key, char *value, int *count)
{
	char		**ret;
	char		*tmp;
	int			tab_len;
	int			flag_key;

	tab_len = -1;
	flag_key = 1;
	while (tab[++tab_len] && tab[tab_len][0])
		flag_key = !cmp_spe(tab[tab_len], key, '=') ? 0 : flag_key;
	ret = (char **)malloc(sizeof(char *) * (tab_len + 1 + flag_key));
	ret[tab_len + flag_key] = NULL;
	*count = -1;
	while (++(*count) < tab_len)
	{
		if (cmp_spe(tab[*count], key, '='))
			ret[*count] = duplicate_str(tab[*count]);
		else
		{
			tmp = ft_strcat_in_new_str(key, "=");
			ret[*count] = ft_strcat_in_new_str(tmp, value);
		}
		free(tab[*count]);
	}
	free(tab);
	return (ret);
}

char		**add_to_env(char **tab, char *keyword, char *value)
{
	char		**ret;
	char		*tmp;
	int			tab_len;
	int			count;
	int			flag_key;

	flag_key = 1;
	ret = NULL;
	if (tab == NULL || tab[0] == NULL)
		ret = additionnal_ate_1(&count, tab);
	else
	{
		tab_len = -1;
		while (tab[++tab_len] && tab[tab_len][0])
			flag_key = !cmp_spe(tab[tab_len], keyword, '=') ? 0 : flag_key;
		ret = additionnal_ate_2(tab, keyword, value, &count);
	}
	if (flag_key == 1)
	{
		tmp = ft_strcat_in_new_str(keyword, "=");
		ret[count] = ft_strcat_in_new_str(tmp, value);
		free(tmp);
	}
	return (ret);
}

void		additionnal_rfe(int tab_len, char **env, char *key_w, char **ret)
{
	int		count;
	int		index;

	count = -1;
	index = -1;
	while (++count < tab_len)
	{
		if (cmp_spe(env[count], key_w, '='))
			ret[++index] = duplicate_str(env[count]);
		free(env[count]);
	}
	free(env);
	return ;
}

char		**remove_from_env(char **env, char *keyword)
{
	int		tab_len;
	int		flag_key;
	char	**ret;

	flag_key = -1;
	if (env == NULL || env[0] == NULL)
	{
		ft_putendl_fd("env is null, nothing to remove from env", 2);
		return (env);
	}
	tab_len = -1;
	while (env[++tab_len] && env[tab_len][0])
		flag_key = !cmp_spe(env[tab_len], keyword, '=') ? tab_len : flag_key;
	if (flag_key == -1)
	{
		ft_putendl_fd("keyword not found in env", 2);
		return (env);
	}
	else
		ret = (char **)malloc(sizeof(char *) * tab_len);
	ret[tab_len - 1] = NULL;
	additionnal_rfe(tab_len, env, keyword, ret);
	return (ret);
}