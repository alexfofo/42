/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:25:01 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:25:02 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "sh.h"

char		*ft_strcat_in_new_str(char *s1, char *s2)
{
	int			i;
	int			sz_1;
	int			sz_2;
	char		*ret;

	i = 0;
	sz_1 = ft_strlen(s1);
	sz_2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (sz_1 + sz_2 + 1));
	ft_bzero(ret, sz_1 + sz_2 + 1);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}

char		*duplicate_str(char *str)
{
	char		*dup;
	int			str_size;
	int			size;

	str_size = ft_strlen(str);
	size = str_size + 1;
	dup = (char *)malloc(sizeof(char) * size);
	ft_bzero(dup, size);
	if (str_size > 0)
		ft_strcat(dup, str);
	return (dup);
}

int			cmp_spe(char *s1, char *s2, char ref)
{
	int		i;
	int		j;

	i = -1;
	while (s1[++i] && s1[i] != ref)
		;
	if (!s1[i])
		return (-1);
	j = -1;
	while (++j < i)
	{
		if (s1[j] != s2[j])
			return (-1);
	}
	if (s2[j])
		return (-1);
	return (0);
}

char		**cp_tab_str(char **tab)
{
	char		**ret;
	int			tab_len;
	int			count;

	ret = NULL;
	if (tab == NULL || tab[0] == NULL)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		ret[0] = NULL;
		return (ret);
	}
	tab_len = -1;
	while (tab[++tab_len] && tab[tab_len][0])
		;
	ret = (char **)malloc(sizeof(char *) * (tab_len + 1));
	count = -1;
	while (++count < tab_len)
		ret[count] = duplicate_str(tab[count]);
	ret[count] = NULL;
	return (ret);
}

void		print_tab_str(char **tab)
{
	int		i;

	i = -1;
	while (tab && tab[++i])
		ft_putendl(tab[i]);
	return ;
}