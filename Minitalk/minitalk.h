/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 17:16:33 by rcherik           #+#    #+#             */
/*   Updated: 2014/02/09 12:51:56 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putswag(char *s);
void		ft_error(char *s);
int			ft_power(int n, int power);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_strlen(char *s);
void		ft_putnbr(int n);
char		*ft_strjoin_c(char *s1, char c);
char		*ft_strnew(size_t size);
char		*ft_strcpy(char *s1, char *s2);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
