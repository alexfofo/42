/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:55:14 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:55:15 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		str_in_tab_str(char *str, char **tab, int size_tab)
{
	int		i;

	if (!tab || !(tab[0]))
		return (-1);
	i = -1;
	while (++i < size_tab)
	{
		if (ft_strcmp(tab[i], str) == 0)
			return (1);
	}
	return (0);
}

char	*get_bigger_str_in_tab(char **tab, int count)
{
	int		i;
	char	*big;

	i = -1;
	if (!tab || !tab[0])
		return (NULL);
	big = tab[0];
	while (++i < count)
	{
		if (ft_strcmp(big, tab[i]) < 0)
			big = tab[i];
	}
	return (big);
}

char	**sort_in_ascii(char **old_tab, char **new_tab, int count)
{
	int				i;
	int				j;
	char			*small;

	i = -1;
	if (old_tab == NULL)
		return (NULL);
	if (new_tab == NULL)
		new_tab = (char **)malloc(sizeof(char *) * (count + 1));
	while (++i < count)
	{
		small = get_bigger_str_in_tab(old_tab, count);
		j = -1;
		while (++j < count)
		{
			if ((str_in_tab_str(old_tab[j], new_tab, i) <= 0)
				&& ft_strcmp(old_tab[j], small) < 0)
				small = old_tab[j];
		}
		new_tab[i] = duplicate_str(small);
	}
	new_tab[i] = (char *)malloc(sizeof(char));
	ft_bzero(new_tab[i], 1);
	return (new_tab);
}
