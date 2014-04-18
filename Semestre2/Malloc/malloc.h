/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 11:45:14 by afollin           #+#    #+#             */
/*   Updated: 2014/04/18 17:20:45 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>

typedef struct		s_mem
{
	void			*addr;
	size_t			len;
	struct s_mem	*next;
}					t_mem;

void				fill_tmem(t_mem **tmem, void *addr, size_t size);

#endif
