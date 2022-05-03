/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/03 15:21:52 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	text(t_fdf *data)
{
	int	place;

	if (data->tip_to_user == 1)
		mlx_string_put(data->mlx, data->win, 550, 150, 0xFF00AA, \
			"-- Rotate first with P, then change height --");
	data->tip_to_user = 0;
	place = 60;
	mlx_string_put(data->mlx, data->win, 85, place, 0xA64FFF, \
		"Here is how to use:");
	mlx_string_put(data->mlx, data->win, 95, place += 30, 0x7ca9f4, \
		"Arrows to move");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"P    to change projection");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"Z/X  to zoom");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"C    to change color");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"O    restarts colors");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"+/-  change height");
	mlx_string_put(data->mlx, data->win, 95, place += 20, 0x7ca9f4, \
		"ESC  to quit");
}

void	rotate_point(t_fdf *data, float *a, float *b, float c)
{
	float	x;
	float	y;


	x = *a;
	y = *b;
	if (data->rotate == 1)
	{
		*a = (x - y) / sqrt(2);
		*b = ((x + (2 * y)) - (c * 4)) / sqrt(6);
	}
	if (data->rotate == 2)
	{
		*a = (x - y + 500) / sqrt(2);
		*b = ((x + (2.3 * y)) - (c * 4)) / sqrt(20);
	}
	*a += data->start_point + data->where_x;
	*b += data->start_point + data->where_y;
}


void	rotate_map(t_fdf *data, int count_points, t_point *p, int height)
{
	int	i;

	i = 0;
	while (i < count_points)
	{
		rotate_point(data, &(p[i].x), &(p[i].y), (p[i].z * height));
		i++;
	}
}

void	set_points(t_fdf *data, t_point *points)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
	while (row < data->r)
	{
		while (column < data->c)
		{
			points[i].x = column * data->size;
			points[i].y = row * data->size;
			points[i].z = data->arr[i];
			i++;
			column++;
		}
		row++;
		column = 0;
	}
}

int	key(int button, t_fdf *data)
{
	ft_putnbr(button);
	if (button == 6 || button == 122 || button == 7 || button == 120)
		change_map_size(button, data);
	if (button == 99 || button == 111 || button == 8 || button == 31)
		set_color(data, button);
	if (button == 27 || button == 45 || button == 24 || button == 43)
		change_height(button, data);
	if (button == 112 || button == 35)
		map_rotate(data);
	if (button == 65363 || button == 65362 || button == 65361 || button == 65364 \
		|| button == 123 || button == 124 || button == 125 || button == 126)
		change_position(button, data);
	if (button == 65307 || button == 53)
		exit(1);
	new_drawing(data);
	return (0);
}

void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
