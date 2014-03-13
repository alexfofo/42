/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:13:49 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:15:00 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL3_H
# define MINISHELL3_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

# define	MAX_KEY_LEN					6
# define	P_LEN						4

# define	KEY_ENTER(buf)				ft_is_key_enter(buf)
# define	KEY_DEL_LEFT(buf)			ft_is_key_del_left(buf)
# define	KEY_DEL_RIGHT(buf)			ft_is_key_del_right(buf)
# define	KEY_ARROW_UP(buf)			ft_is_key_arrow_up(buf)
# define	KEY_ARROW_DOWN(buf)			ft_is_key_arrow_down(buf)
# define	KEY_ARROW_LEFT(buf)			ft_is_key_arrow_left(buf)
# define	KEY_ARROW_RIGHT(buf)		ft_is_key_arrow_right(buf)
# define	KEY_OPT_ARROW_UP(buf)		ft_is_key_opt_arrow_up(buf)
# define	KEY_OPT_ARROW_DOWN(buf)		ft_is_key_opt_arrow_down(buf)
# define	KEY_OPT_ARROW_LEFT(buf)		ft_is_key_opt_arrow_left(buf)
# define	KEY_OPT_ARROW_RIGHT(buf)	ft_is_key_opt_arrow_right(buf)
# define	KEY_CTRL_A(buf)				ft_is_key_ctrl_a(buf)
# define	KEY_CTRL_E(buf)				ft_is_key_ctrl_e(buf)
# define	KEY_CTRL_U(buf)				ft_is_key_ctrl_u(buf)
# define	KEY_CTRL_I(buf)				ft_is_key_ctrl_i(buf)
# define	KEY_CTRL_H(buf)				ft_is_key_ctrl_h(buf)
# define	KEY_CTRL_R(buf)				ft_is_key_ctrl_r(buf)
# define	KEY_CTRL_T(buf)				ft_is_key_ctrl_t(buf)
# define	KEY_CTRL_F(buf)				ft_is_key_ctrl_f(buf)
# define	KEY_CTRL_G(buf)				ft_is_key_ctrl_g(buf)

typedef struct	s_sl
{
	char		c;
	int			cursor;
	struct s_sl	*next;
	struct s_sl	*prev;
}				t_sl;

typedef struct	s_hl
{
	t_sl		*hist;
	struct s_hl	*next;
	struct s_hl	*prev;
}				t_hl;

typedef struct	s_save
{
	int			cursor;
	int			co;
	int			hist_nb;
	int			fd;
	int			hlen;
	t_sl		*copy;
}				t_save;

int		ft_put_or_del_char(char *buf, t_sl **list, t_save *save, t_hl **hlist);
int		ft_list_become_chtab(char **line, t_sl **list);
int		ft_cut_copy_or_paste(char *buf, t_sl **list, t_save *save);
t_sl	*ft_listdup(t_sl *list);
int		ft_fast_move(char *buf, t_sl **list, int *cursor, int co);
int		ft_historic(char *buf, t_sl **list, t_save *save, t_hl **hlist);
int		ft_print(t_sl *list, t_save *save, int old_line);
int		ft_in_history(t_hl **hlist, t_sl **list);
t_sl	*ft_list_new_elem(char c);
void	ft_list_del_elem(t_sl **list, int cursor);
int		ft_putc(int c);
int		ft_is_key_opt_arrow_up(char *buf);
int		ft_is_key_opt_arrow_down(char *buf);
int		ft_is_key_opt_arrow_left(char *buf);
int		ft_is_key_opt_arrow_right(char *buf);
int		ft_is_key_arrow_up(char *buf);
int		ft_is_key_arrow_down(char *buf);
int		ft_is_key_arrow_left(char *buf);
int		ft_is_key_arrow_right(char *buf);
int		ft_is_key_del_left(char *buf);
int		ft_is_key_del_right(char *buf);
int		ft_is_key_enter(char *buf);
int		ft_is_key_ctrl_u(char *buf);
int		ft_is_key_ctrl_i(char *buf);
int		ft_is_key_ctrl_h(char *buf);
int		ft_is_key_ctrl_a(char *buf);
int		ft_is_key_ctrl_e(char *buf);
int		ft_is_key_ctrl_r(char *buf);
int		ft_is_key_ctrl_t(char *buf);
int		ft_is_key_ctrl_f(char *buf);
int		ft_is_key_ctrl_g(char *buf);
int		ft_slist_len(t_sl *list);
int		ft_hlist_len(t_hl *list);
int		ft_save_final_list(t_hl **hlist, char **line);
int		ft_list_put_elem(char c, t_sl **list, int cursor);
void	ft_launch(char **cp_env, char **split, char **splipe);
char	*search_in_env(char **env, char *var);
void	ft_son(int *fildes, int father, char **splipe, char **env);
void	ft_else(char *line);
void	ft_son_of_fill_files(char *line, int i, char *cmd, char **env);
void	ft_handle_signal(int s);
int		ft_check_known_cmd(char *line, char **env);
void	ft_cat_setenv(char **env, char **tmp);
void	ft_cd(const char *path, char *line, char **env);
void	ft_unsetenv(char *line, char **env);
int		ft_is_exec(char *line, char **env);
void	ft_setenv(char *line, char **env);
void	ft_check_ft(char *line, char **env);
int		ft_error_setenv(char **tmp);
void	ft_env(char **env);
void	ft_pipe(char **splipe, char *ret, char **env);
int		ft_ischevron(char *line);
char	*ft_name_file(char *line);
void	ft_do_chev(char *line, char **env);
void	ft_fill_files(char *line, char **env);
int		ft_create_files(char *line);
char	*ft_what_cmd(char *line);
int		ft_open(char *line, int i);
int		ft_init_terminal_mode(void);
int		ft_default_terminal_mode(void);

#endif /* !MINISHELL3_H */
