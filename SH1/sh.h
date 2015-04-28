/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:23:17 by afollin           #+#    #+#             */
/*   Updated: 2015/04/28 17:23:19 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"

char		**cd_stuff(char *line, int *f, char **env);

void		execute_stuff(char **tab_str, int *f, char **env);

char		**env_stuff(char *line, int *f, char **env);
char		*get_env_var(char **env, char *var);

char		**add_to_env(char **tab, char *keyword, char *value);
char		**remove_from_env(char **env, char *keyword);

int			count_word(char *str);
char		*get_word_x(char *str, int x);
char		*get_word_x_spe(char *str, int x, char c);

char		*ft_strcat_in_new_str(char *s1, char *s2);

char		*duplicate_str(char *str);
int			cmp_spe(char *s1, char *s2, char ref);
char		**cp_tab_str(char **tab);
void		print_tab_str(char **tab);

#endif
