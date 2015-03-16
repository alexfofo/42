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

static int		str_index_in_tab_int(int index, int *tab, int size_tab)
{
	int		i;

	i = -1;
	while (++i < size_tab)
	{
		if (index == tab[i])
			return (1);
	}
	return (0);
}

static char		*get_bigger_str_in_tab(char **tab, int count, int *x)
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
		{
			big = tab[i];
			*x = i;
		}
	}
	return (big);
}

static void		fk_norme(char **old_tab, char **new_tab, int *normed, int *tab)
{
	char			*small;
	int				tmp;
	int				i;
	int				j;

	i = normed[1];
	small = get_bigger_str_in_tab(old_tab, normed[0], &tmp);
	j = -1;
	while (++j < normed[0])
	{
		if ((str_index_in_tab_int(j, tab, i) <= 0)
			&& ft_strcmp(old_tab[j], small) < 0)
		{
			small = old_tab[j];
			tmp = j;
		}
	}
	new_tab[i] = duplicate_str(small);
	tab[i] = tmp;
	return ;
}

char			**sort_in_ascii(char **old_tab, int count)
{
	int				i;
	char			**new_tab;
	int				tab[count];
	int				norme_tab[2];

	norme_tab[0] = count;
	i = -1;
	while (++i < count)
		tab[i] = -1;
	if (old_tab == NULL)
		return (NULL);
	new_tab = (char **)malloc(sizeof(char *) * (count + 1));
	i = -1;
	while (++i < count)
	{
		norme_tab[1] = i;
		fk_norme(old_tab, new_tab, norme_tab, tab);
	}
	new_tab[i] = duplicate_str("\0");
	return (new_tab);
}
