/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:56:02 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:56:03 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	**extend_tab(char **tab, char *name)
{
	int		count;
	int		i;
	char	**ret;

	count = 0;
	if (tab == NULL)
	{
		ret = (char **)malloc(sizeof(char *) * 2);
		ret[0] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[0], ft_strlen(name) + 1);
		ft_strcat(ret[0], name);

		ret[1] = (char *)malloc(sizeof(char));
		ft_bzero(ret[1], 1);
	}
	else
	{
		while (tab[count] && tab[count][0])
		{
			++count;
		}
		ret = (char **)malloc(sizeof(char *) * (count + 2));
		count = -1;
		while (tab[++count] && tab[count][0])
		{
			i = 0;
			while (tab[count][i])
				++i;
			ret[count] = (char *)malloc(sizeof(char) * (i + 1));
			ft_bzero(ret[count], i + 1);
			ft_strcat(ret[count], tab[count]);
		}
		ret[count] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[count], ft_strlen(name) + 1);
		ft_strcat(ret[count], name);
		ret[count + 1] = (char *)malloc(sizeof(char));
		ft_bzero(ret[count + 1], 1);
	}
	//free tab
	return ret;
}

char	**sort_option_a(char *options, char *name, char **elemSorted, int *i)
{
	int			toAdd;

	toAdd = 0;
	if (options && ft_strchr(options, 'a'))
		toAdd = 1;
	else if (name && name[0] != '.')
		toAdd = 1;
	if (toAdd == 1)
	{
		elemSorted = extend_tab(elemSorted, name);
		*i = *i + 1;
	}
	return elemSorted;
}
