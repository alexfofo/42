/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:11:33 by afollin           #+#    #+#             */
/*   Updated: 2015/03/05 15:11:34 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>

# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>

void	ft_exit(char *msg, char *options, char *word);
int		check_opt(char *options, char c, char *ref);
int		check_special_options(int *tmp, int *index, char *word);
char	*get_options(int argc, char **argv, int *index);
char	**get_args(int argc, char **argv, int first_arg);

// void	print_option_l(char *path, char *name);
int		compute_blocks(char *path, char *options);
void	option_lil_l(char *path, char **to_show, int tot_block, int nb_elem);

char	**extend_tab(char **tab, char *name);
char	**sort_option_a(char *options, char *name, char **elem_sorted, int *i);

char	**sort_option_lil_t(char **old_tab, char *path, int count);
char	**sort_option_lil_r(char **old_tab, char **new_tab, int count);

// int		str_in_tab_str(char *str, char **tab, int size_tab);
// char	*get_bigger_str_in_tab(char **tab, int count);
char	**sort_in_ascii(char **old_tab, int count);

char	*create_str_suffix(char *s1, char *s2);
int		ft_is_dir(char *entity_path);
char	*duplicate_str(char *str);
char	**extend_tab_str(char **tab, char *str);
void	print_tab_str(char **tab);

void	option_big_r(char *path, char *options);

char	**get_elems_to_display(char *options, char *name, int *nb_elem);
char	**sort_elems(char *options, char **elem_to_sort, char *path);
void	ft_ls(char *options, char **args, int ac, int flag);
char	**sort_files_and_dir(char **args, int nb_args);

#endif
