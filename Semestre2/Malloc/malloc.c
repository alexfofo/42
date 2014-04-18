/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:02:37 by afollin           #+#    #+#             */
/*   Updated: 2014/04/18 17:20:59 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>

#include "malloc.h"

static void		*malloc_tiny(size_t size, size_t ps)
{
	static void	*addr;
	static int	i = 0;

	if (i == 0 || size + i > ps)
	{
		addr = mmap(0, ps, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
					-1, 0);
		i = 0;
	}
	addr += i;
	i += size;
	return (addr);
}

static void		*malloc_small(size_t size, size_t ps)
{
	static void	*addr;
	static int	i = 0;

	if (i == 0 || size + i > ps)
	{
		addr = mmap(0, ps, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
					-1, 0);
		i = 0;
	}
	addr += i;
	i += size;
	return (addr);
}

static void		*malloc_large(size_t size)
{
	static void	*addr;

	addr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
				-1, 0);
	return (addr);
}

void			*malloc(size_t size)
{
	void			*addr;
	size_t			ps;
	static t_mem	*tmem = NULL;

	ps = getpagesize();
	if (size < 1)
		return (NULL);
	else if (size < ((ps / 100) * 3))
		addr = malloc_tiny(size, ps * 3);
	else if (size < ps)
		addr = malloc_small(size, ps * 100);
	else
		addr = malloc_large(size);
	fill_tmem(&tmem, addr, size);
	return (addr);
}
