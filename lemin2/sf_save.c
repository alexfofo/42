/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:51:52 by afollin           #+#    #+#             */
/*   Updated: 2014/03/05 14:58:23 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"

t_link			*ft_new_link(void)
{
	t_link		*link;

	link = (t_link *)malloc(sizeof(t_link));
	link->name = NULL;
	link->next = NULL;
	return (link);
}
