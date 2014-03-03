/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:56:05 by afollin           #+#    #+#             */
/*   Updated: 2013/12/06 15:03:45 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tdel;

	tdel = *alst;
	tmp = *alst;
	while (tmp)
	{
		del((tdel)->content, (tdel)->content_size);
		free((void *)tdel);
		tmp = tmp->next;
		tdel = tmp;
	}
	*alst = NULL;
}
