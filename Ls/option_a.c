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

char	**sort_option_a(char *options, char *name, char **elem_sorted, int *i)
{
	int			to_add;

	to_add = 0;
	if (options && ft_strchr(options, 'a'))
		to_add = 1;
	else if (name && name[0] != '.')
		to_add = 1;
	if (to_add == 1)
	{
		elem_sorted = extend_tab_str(elem_sorted, name);
		*i = *i + 1;
	}
	return (elem_sorted);
}
