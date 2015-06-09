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

int AAA = 0;
int BBB = 0;

int	glob1 = 0;
int	glob2 = 0;

void	*create_img(void *mlx_ptr, int width, int height)
{
	int		i;
	int		j;
	int		k;
	void	*img;
	char	*img_color;
	int		bits_per_pixel = 0;
	int		size_line = 0;
	int		endian = 0;

	img = mlx_new_image(mlx_ptr, width, height);
	img_color = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	printf("bits_per_pixel: %d\nsize_line: %d\nendian: %d\n", bits_per_pixel, size_line, endian);
	i = 0;
	k = 0;
	while (k < 20)
	{
		i = 0;
		while (i < 100)
		{
			j = -1;
			while (++j < 4)
			{
				if (j == 0)//blue
					img_color[(5 + k) * size_line + i + j] = 255;
				else if (j == 1)//green
					img_color[(5 + k) * size_line + i + j] = 255;
				else if (j == 2)//red
					img_color[(5 + k) * size_line + i + j] = 0;
				else if (j == 3)//transparency
					img_color[(5 + k) * size_line + i + j] = 0;
			}
			i = i + 4;
		}
		++k;
	}
	return (img);
}

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
	void	*img;
	char	*img_color;
	int		bits_per_pixel = 0;
	int		size_line = 0;
	int		endian = 0;

	y = 100 + AAA;
	i = 0;
	while (i < 100)
	{
		x = 100 + BBB;
		j = 0;
		while (j < 100)
		{
			mlx_pixel_put(mlx, win, x + j, y + i, 0xFF0000);
			++j;
		}
		++i;
	}
	y = 130 + AAA;
	i = 0;
	while (i < 40)
	{
		x = 130 + BBB;
		j = 0;
		while (j < 40)
		{
			mlx_pixel_put(mlx, win, x + j, y + i, 0x00FF00);
			++j;
		}
		++i;
	}

	img = mlx_new_image(mlx, 30, 30);
	img_color = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	printf("bits_per_pixel: %d\nsize_line: %d\nendian: %d\n", bits_per_pixel, size_line, endian);
	i = 0;
	k = 0;
	while (k < 20)
	{
		i = 20;
		while (i < 100)
		{
			j = -1;
			while (++j < 4)
			{
				if (j == 0)//blue
					img_color[(5 + k) * size_line + i + j] = 255;
				else if (j == 1)//green
					img_color[(5 + k) * size_line + i + j] = 255;
				else if (j == 2)//red
					img_color[(5 + k) * size_line + i + j] = 0;
				else if (j == 3)//transparency
					img_color[(5 + k) * size_line + i + j] = 0;
			}
			i = i + 4;
		}
		++k;
	}
	mlx_put_image_to_window(mlx, win, img, 90, 90);

}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	e = e ? e : NULL;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		glob1 = glob1 - 3;
	if (keycode == 125)
		glob1 = glob1 + 3;
	if (keycode == 123)
		glob2 = glob2 - 3;
	if (keycode == 124)
		glob2 = glob2 + 3;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 90 + glob2, 90 + glob1);
	//draw(e->mlx, e->win);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
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
	e.win = mlx_new_window(e.mlx, 256, 256, "2^8");
	e.img = create_img(e.mlx, 30, 30);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
