/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:27:50 by afollin           #+#    #+#             */
/*   Updated: 2014/03/04 18:25:57 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN2_H
# define LEMIN2_H

# include "libft/includes/libft.h"
# include <stdlib.h>

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_game
{
	int				nb_ant;
	int				i_start;
	int				i_end;
	char			*start;
	char			*end;
	t_room			*room;
	t_room			*tmp_room;
}					t_game;

int					is_comment(char *line);
int					is_number(char *line);
int					how_much_c_in_str(char c, char *str);
int					ft_init_vars(int *index, char **line, t_game *game);
t_game				ft_save_input(void);
int					ft_check_line(int index, char *line);
int					ft_check_coords(int index, char *line);
int					ft_check_links(char *line);
int					ft_save_line(int index, char *line, t_game *game);
t_room				*ft_new_room(void);

#endif /* !LEMLIN2_H */
