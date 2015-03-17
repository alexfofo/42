/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:50:52 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:50:55 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	*create_str_suffix(char *s1, char *s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(ret, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}

int		ft_is_dir(char *entity_path)
{
	struct stat		st;

	if (lstat(entity_path, &st) == -1)
	{
		// ft_putendl(entity_path);
		// perror("ft_ls in is_dir");
		// exit(1);
		return (-1);
	}
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

char	*duplicate_str(char *str)
{
	char	*dup;
	int		str_size;
	int		size;

	str_size = ft_strlen(str);
	size = str_size + 1;
	dup = (char *)malloc(sizeof(char) * size);
	ft_bzero(dup, size);
	if (str_size > 0)
		ft_strcat(dup, str);
	return (dup);
}

char	**extend_tab_str(char **tab, char *str)
{
	char	**extended;
	int		size_tab;
	int		count;

	size_tab = -1;
	count = -1;
	if (tab == NULL || tab[0] == NULL)
	{
		extended = (char **)malloc(sizeof(char *) * 2);
		extended[0] = duplicate_str(str);
		extended[1] = duplicate_str("\0");
		return (extended);
	}
	while (tab[++size_tab][0] != '\0')
		;
	extended = (char **)malloc(sizeof(char *) * (size_tab + 2));
	while (++count < size_tab)
	{
		extended[count] = duplicate_str(tab[count]);
		free(tab[count]);
	}
	extended[count] = duplicate_str(str);
	extended[++count] = duplicate_str("\0");
	free(tab);
	return (extended);
}

void	print_tab_str(char **tab)
{
	int		i;

	ft_putstr("	in printTabStr\n");
	i = -1;
	while (tab[++i][0])
	{
		ft_putstr("		tab[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putendl(tab[i]);
	}
	ft_putstr("	out printTabStr\n");
	return ;
}
