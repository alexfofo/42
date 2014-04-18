/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 11:50:13 by afollin           #+#    #+#             */
/*   Updated: 2014/04/18 17:19:33 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

static void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n--)
	{
		*c1 = *c2;
		c1++;
		c2++;
	}
	return (s1);
}

void			fill_tmem(t_mem **t, void *addr, size_t size)
{
	t_mem			*move;
	t_mem			*tmp;
	size_t			ps;
	static size_t	i = 0;
	static size_t	j = 1;

	ps = j * getpagesize();
	if (*t == NULL)
		*t = mmap(0, ps, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (i + sizeof(**t) > ps)
	{
		j++;
		ps = j * getpagesize();
		tmp = mmap(0, ps, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
		tmp = ft_memcpy(tmp, *t, ps - getpagesize());
		munmap(*t, ps - getpagesize());
		*t = tmp;
	}
	move = *t + i;
	move->addr = addr;
	move->len = size;
	i += sizeof(**t);
}
