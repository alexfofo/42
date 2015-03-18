/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:30:34 by afollin           #+#    #+#             */
/*   Updated: 2015/02/05 13:30:35 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char			**sort_elems(char *options, char **elem_to_sort, char *path)
{
	int			count;
	int			i;

	i = -1;
	count = 0;
	while (elem_to_sort[count] && elem_to_sort[count][0])
		++count;
	elem_to_sort = sort_in_ascii(elem_to_sort, count);
	if (options && ft_strchr(options, 't'))
		elem_to_sort = sort_option_lil_t(elem_to_sort, path, count);
	if (options && ft_strchr(options, 'r'))
		elem_to_sort = sort_option_lil_r(elem_to_sort, NULL, count);
	return (elem_to_sort);
}

static char		**sort_files_and_dir(char **args, int nb_args, int index)
{
	char	**new_args;
	int		count;

	count = -1;
	new_args = (char **)malloc(sizeof(char *) * (nb_args + 1));
	while (++count < nb_args)
	{
		if (ft_is_dir(args[count]) == -1)
			new_args[++index] = duplicate_str(args[count]);
	}
	count = -1;
	while (++count < nb_args)
	{
		if (!ft_is_dir(args[count]))
			new_args[++index] = duplicate_str(args[count]);
	}
	count = -1;
	while (++count < nb_args)
	{
		if (ft_is_dir(args[count]) == 1)
			new_args[++index] = duplicate_str(args[count]);
	}
	new_args[++index] = duplicate_str("\0");
	return (new_args);
}

static char		**for_the_luv_of_norme(char **args, char *options, int sub)
{
	args = sort_in_ascii(args, sub);
	if (options && ft_strchr(options, 't'))
		args = sort_option_lil_t(args, NULL, sub);
	if (options && ft_strchr(options, 'r'))
		args = sort_option_lil_r(args, NULL, sub);
	args = sort_files_and_dir(args, sub, -1);
	return (args);
}

int				main(int argc, char **argv)
{
	char	*options;
	int		index;
	char	**args;

	index = 0;
	options = get_options(argc, argv, &index, 0);
	args = get_args(argc, argv, index);
	if (args == NULL)
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = duplicate_str("./\0");
		args[1] = duplicate_str("\0");
		++argc;
		if (index == 0)
			++index;
	}
	if (argc - index > 1)
		args = for_the_luv_of_norme(args, options, argc - index);
	ft_ls(options, args, argc - index, 1);
	return (0);
}
