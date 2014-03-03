/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:09:03 by afollin           #+#    #+#             */
/*   Updated: 2014/03/03 16:40:19 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			main(void)
{
	ft_save_input();
	return (0);
}

t_game		ft_save_input()
{
	t_game		game;
	char		*line;
	int			index;

	ft_init_vars(&index, &line, &game);
	while (get_next_line(0, &line))
	{
		if (!(is_comment(line)))
		{
			index = ft_check_line(index, line);
			if (index >= 0)
				index = ft_save_line(index, line);
			if (index < 0)
				index *= -1;
		}
	}
	return(game);
}

int			ft_init_vars(int *index, char **line, t_game *game)
{
	index = 0;
	line = NULL;
	game->nb_ant = 0;
	game->start = NULL;
	game->end = NULL;
	return (0);
}
