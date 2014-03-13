/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:48:08 by afollin           #+#    #+#             */
/*   Updated: 2013/12/11 15:59:58 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	list = (t_list *)malloc(sizeof(*list));
	ptr = (unsigned char *)malloc(sizeof(*ptr) * content_size);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		while (i < content_size)
		{
			*(ptr + i) = *((unsigned char *)content + i);
			i++;
		}
		list->content = ptr;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
