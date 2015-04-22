/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:22:52 by afollin           #+#    #+#             */
/*   Updated: 2015/04/22 18:11:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char    *duplicate_str(char *str)
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

char		**cp_tab_str(char **tab)
{
	char		**ret;
	int			tab_len;
	int			count;

	ret = NULL;
	if (tab == NULL || tab[0] == NULL)
		return (NULL);
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

void    print_tab_str(char **tab)
{
	int             i;

	i = -1;
	while (tab && tab[++i])
		ft_putendl(tab[i]);
	return ;
}

void		early_exit(int argc, char **argv)
{
	int		i;

	i = -1;
	argc = 0;
	ft_putstr("usage: ");
	ft_putendl(argv[0]);
	exit(0);
	return ;
}

void		env_stuff(char *line, int *f, char **env)
{
	if (*f)
		return ;
	if (!ft_strcmp(line, "env"))
		print_tab_str(env);
	return ;
}

//void		cd_stuff(char *line, int *f)
//{
//	if (f)
//		return ;
//	return ;
//}



int			main(int argc, char **argv, char **env)
{
	char		**cp_env;
	char		*line;
	int			cute_flag;

	if (argc != 1)
		early_exit(argc, argv);
	cp_env = cp_tab_str(env);
	cute_flag = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line,"exit") == 0)
			return (1);
		env_stuff(line, &cute_flag, env);
		//		cd_stuff(line, &cute_flag);
	}
	//printf("returned: %d, line: %s\n", returned, line);

	return (0);
}

