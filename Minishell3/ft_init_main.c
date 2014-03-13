/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:05:17 by afollin           #+#    #+#             */
/*   Updated: 2014/02/07 18:38:09 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_minishell3.h"
#include "libft.h"

int		ft_init_terminal_mode(void)
{
	char			*term_name;
	struct termios	tattr;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag &= ~(OPOST);
	tattr.c_lflag &= ~(ICANON);
	tattr.c_lflag &= ~(ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}

int		ft_default_terminal_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag |= ~(OPOST);
	tattr.c_lflag |= ~(ICANON);
	tattr.c_lflag |= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}

void	ft_launch(char **cp_env, char **split, char **splipe)
{
	char			*line;
	t_hl			*hlist;

	line = NULL;
	hlist = NULL;
	while (ft_save_final_list(&hlist, &line) != -1 && ft_strcmp(line, "exit"))
	{
		split = ft_strsplit(line, ';');
		while (*split)
		{
			splipe = ft_strsplit(*split, '|');
			if (splipe[1] == NULL)
				ft_check_ft(ft_strtrim(*split), cp_env);
			else
				ft_pipe(splipe, NULL, cp_env);
			split++;
		}
	}
}
