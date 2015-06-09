/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 12:49:10 by afollin           #+#    #+#             */
/*   Updated: 2015/06/08 12:49:11 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf.h"

// int AAA = 0;
// int BBB = 0;

void	my_put_pixel_to_img(char *img_color, int x, int y, int color, int size_line)
{
	img_color[y * size_line + x] = color | 0x11;
	img_color[y * size_line + x + 1] = color | 0x1100;
	img_color[y * size_line + x + 2] = color | 0x110000;
	img_color[y * size_line + x + 3] = color | 0x11000000;
	return ;
}

void	*draw_background_img(void *mlx)
{
	int		i;
	int		j;
	void	*img;
	char	*img_color;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	bits_per_pixel = 0;
	size_line = 0;
	endian = 0;
	img = mlx_new_image(mlx, 1024 * 4, 1024 * 4);
	img_color = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < 1024 / 2)
	{
		j = -1;
		while (++j < 1024 * 4)
			my_put_pixel_to_img(img_color, j, i, 0x00BBBBBB, size_line);
		++i;
	}
	while (i < 1024)
	{
		j = -1;
		while (++j < 1024 * 4)
			my_put_pixel_to_img(img_color, j, i, 0x00888888, size_line);
		++i;
	}
	return (img);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	e = e ? e : NULL;
	if (keycode == 53)
		exit(0);
	// if (keycode == 126)
	// 	AAA = AAA - 3;
	// if (keycode == 125)
	// 	AAA = AAA + 3;
	// if (keycode == 123)
	// 	BBB = BBB - 3;
	// if (keycode == 124)
	// 	BBB = BBB + 3;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	// draw_background_img(e->mlx);
	return (0);
}

int		expose_hook(t_env *e)
{
	e->img = draw_background_img(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	e = e ? e : NULL;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		main()
{
	t_env		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1024, 1024, "2^8");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
