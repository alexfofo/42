/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_lil_t_lil_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:55:53 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:55:54 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		get_tab_int(char **old_tab, char *path, int count, int *tab_int)
{
	struct stat		s;
	int				i;
	char			*p_name;

	i = -1;
	while (++i < count)
	{
		if (!path)
		{
			p_name = (char *)malloc(sizeof(char) * (ft_strlen(old_tab[i]) + 1));
			ft_bzero(p_name, ft_strlen(old_tab[i]) + 1);
		}
		if (path)
		{
			p_name = (char *)malloc(sizeof(char) * (ft_strlen(old_tab[i])
				+ ft_strlen(path) + 1));
			ft_bzero(p_name, ft_strlen(old_tab[i]) + ft_strlen(path) + 1);
			ft_strcat(p_name, path);
		}
		ft_strcat(p_name, old_tab[i]);
		lstat(p_name, &s);
		tab_int[i] = s.st_mtime;
		free(p_name);
	}
	return ;
}

static void		get_tab_int_bis(int *tab_int_bis, int *tab_int, int count)
{
	int		i;
	int		j;
	int		tmp;
	int		tmp_bis;

	j = -1;
	while (++j < count)
	{
		i = -1;
		tmp = tab_int[0];
		tmp_bis = -1;
		while (++i < count)
		{
			if ((tab_int[i] > -1 && tab_int[i] > tmp) || tmp_bis == -1)
			{
				tmp = tab_int[i];
				tmp_bis = i;
			}
		}
		tab_int[tmp_bis] = -1;
		tab_int_bis[j] = tmp_bis;
	}
	return ;
}

char			**sort_option_lil_t(char **old_tab, char *path, int count)
{
	char			**new_tab;
	int				i;
	int				tab_int[count];
	int				tab_int_bis[count];

	new_tab = (char **)malloc(sizeof(char *) * (count + 1));
	get_tab_int(old_tab, path, count, tab_int);
	get_tab_int_bis(tab_int_bis, tab_int, count);
	i = -1;
	while (++i < count)
	{
		new_tab[i] = (char *)malloc(sizeof(char)
			* (ft_strlen(old_tab[tab_int_bis[i]]) + 1));
		ft_bzero(new_tab[i], ft_strlen(old_tab[tab_int_bis[i]]) + 1);
		ft_strcat(new_tab[i], old_tab[tab_int_bis[i]]);
	}
	new_tab[i] = (char *)malloc(sizeof(char));
	ft_bzero(new_tab[i], 1);
	return (new_tab);
}

char			**sort_option_lil_r(char **old_tab, char **new_tab, int count)
{
	int				i;
	int				j;
	char			*small;

	if (new_tab == NULL)
		new_tab = (char **)malloc(sizeof(char *) * (count + 1));
	j = -1;
	while (--count >= 0)
	{
		new_tab[++j] = (char *)malloc(sizeof(char)
			* (ft_strlen(old_tab[count]) + 1));
		ft_bzero(new_tab[j], ft_strlen(old_tab[count]) + 1);
		ft_strcat(new_tab[j], old_tab[count]);
	}
	new_tab[j + 1] = (char *)malloc(sizeof(char));
	ft_bzero(new_tab[j + 1], 1);
	return (new_tab);
}
