/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_call.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 11:34:40 by afollin           #+#    #+#             */
/*   Updated: 2014/03/12 17:10:16 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*c_calls(char *str, char *s1)
{
	void		*s2;

	s2 = NULL;
	if (!ft_strcmp(str, "trim"))
		s2 = ft_strtrim(s1);
	else if (!(ft_strcmp(str, "dup")))
		s2 = ft_strdup(s1);
	gfree(s1);
	return (s2);
}

void	*c_calld(char *str, char *s1, char *s2)
{
	void		*s3;

	s3 = NULL;
	if (!(ft_strcmp(str, "join")))
		s3 = ft_strjoin(s1, s2);
	gfree(s1);
	gfree(s2);
	return (s3);
}
