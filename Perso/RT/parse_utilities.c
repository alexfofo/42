/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:28:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:44:21 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "libft.h"

char		*ft_get_x_word(int x, char *line)
{
	char	*word;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (count < x && *line)
	{
		line++;
		if (*line == ' ' || *line == '\0')
		{
			count++;
			if (count == x)
				line++;
		}
	}
	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	word[i] = '\0';
	while (--i >= 0)
		word[i] = line[i];
	return (word);
}

t_v			ft_get_vect(char *line)
{
	t_v		tv;
	char	*word;

	word = ft_get_x_word(0, line);
	tv.x = atof(word);
	free(word);
	word = ft_get_x_word(1, line);
	tv.y = atof(word);
	free(word);
	word = ft_get_x_word(2, line);
	tv.z = atof(word);
	free(word);
	return (tv);
}

t_c			ft_get_color(char *line)
{
	t_c		tc;
	char	*b;
	char	*g;
	char	*r;

	b = ft_get_x_word(0, line);
	g = ft_get_x_word(1, line);
	r = ft_get_x_word(2, line);
	tc.b = ft_atoi(b);
	tc.g = ft_atoi(g);
	tc.r = ft_atoi(r);
	free(b);
	free(g);
	free(r);
	return (tc);
}
