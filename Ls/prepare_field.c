/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:44:40 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 14:44:43 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_exit(char *msg, char *options, char *word)
{
	if (!options)
		exit(1);
	ft_putstr(msg);
	ft_putendl(word);
	exit(0);
	return ;
}

int		check_opt(char *options, char c, char *ref)
{
	int flag;

	flag = -1;
	while (*ref)
	{
		if (c == *ref)
			flag = 1;
		++ref;
	}
	while (*options && flag > 0)
	{
		if (c == *options)
			flag = 0;
		++options;
	}
	return (flag);
}

int		check_special_options(int *tmp, int *index, char *word)
{
	if (ft_strncmp(word, "-", ft_strlen(word)) == 0)
	{
		--(*index);
		return (1);
	}
	if (ft_strncmp(word, "--", ft_strlen(word)) == 0)
	{
		*tmp = 0;
		return (1);
	}
	return (0);
}

char	*get_options(int argc, char **argv, int *index)
{
	char		*options;
	int			opt;
	int			j;
	int			tmp;
	int			break_flag;

	options = (char *)malloc(sizeof(char) * 6);
	ft_bzero(options, 6);
	break_flag = 0;
	if ((opt = 0) == 0 && argc == 1)
		return (options);
	while (++(*index) < argc && argv[(*index)][0] == '-' && break_flag == 0)
	{
		j = 0;
		while (argv[(*index)][++j])
		{
			if ((tmp = check_opt(options, argv[(*index)][j], "lRart\0")) == 1)
				options[opt++] = argv[(*index)][j];
		}
		if (check_special_options(&tmp, index, argv[(*index)]) == 1)
			break_flag = 1;
		if (tmp == -1)
			ft_exit("Problem, wrong option: ", options, argv[(*index)]);
	}
	return (options);
}

char	**get_args(int argc, char **argv, int first_arg)
{
	char	**args;
	int		sub;
	int		i;

	if ((sub = argc - first_arg) == 0 || first_arg == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (sub + 1));
	i = -1;
	while (++i + first_arg < argc)
	{
		args[i] = (char *)malloc(sizeof(char) *
			(ft_strlen(argv[i + first_arg]) + 1));
		ft_strcpy(args[i], argv[i + first_arg]);
	}
	if (args && !(*args))
		return (NULL);
	return (args);
}
