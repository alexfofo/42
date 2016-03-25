/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:55:36 by afollin           #+#    #+#             */
/*   Updated: 2016/03/07 16:55:42 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct s_ni	t_nigh;

typedef struct		s_cell
{
	char			*name;
	int				pos_x;
	int				pos_y;
	t_nigh			*nighs;
	struct s_cell	*next;
}					t_cell;

struct				s_ni
{
	struct s_cell	*cell;
	struct s_ni		*next;
};

typedef struct		s_tube
{
	t_cell			*cell_one;
	t_cell			*cell_two;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_trail
{
	t_cell			*cell;
	struct s_trail	*next;
}					t_trail;

typedef struct		s_path
{
	t_trail			*trails;
	int				size;
	int				used;
	struct s_path	*next;
}					t_path;

typedef struct		s_resources
{
	int				nb_ant;
	t_cell			*cells;
	t_tube			*tubes;
	t_cell			*start;
	t_cell			*end;
	t_path			*paths;
	t_path			*final_paths;
}					t_resources;

typedef struct		s_ant
{
	int				id;
	t_path			*cur_path;
	t_trail			*cur_trail;
	struct s_ant	*next;
}					t_ant;

/*
**		step_get_nb_ant.c
*/
int					step_get_nb_ant(char *line, t_resources *resources);

/*
**		step_get_cells.c
*/
int					step_get_cells(char *line, t_resources *resources);

/*
**		step_get_tubes.c
*/
int					step_get_tubes(char *line, t_resources *resources);

/*
**		is_comment_or_command.c
*/
int					is_comment_or_command(char *line);

/*
**		utilities.c
*/
void				display_res4(t_resources *res, t_path *tmp, t_trail *tmp2);
void				display_res(t_resources *res);

/*
**		utilities2.c
*/
int					get_size_list_nighs(t_nigh *list);
t_path				*create_path_node(t_trail *trail, int sz);
t_trail				*create_trail_node(t_cell *cell);
void				free_dbl_tab(char **tab);

/*
**		do_lemin_algo.c
*/
char				*do_lemin_algo(t_resources *resources);

/*
**		set_nighs_cells.c
*/
int					set_nighs_cells(t_resources *resources);

/*
**		get_paths.c
*/
int					get_paths(t_resources *r, t_trail *t, t_cell *c, t_nigh *n);

/*
**		get_final_paths.c
*/
t_path				*get_final_paths(t_resources *resources, int mw);

/*
**		print.walk.c
*/
void				print_walk(t_resources *resources);

#endif
