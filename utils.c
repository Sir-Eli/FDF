/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/04/27 18:03:03 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point(t_fdf *data, float *a, float *b, float c)
{
	int	x;
	int	y;

	if (data->rotate == 1)
	{
		x = *a;
		y = *b;
		*a = (x - y) / sqrt(2);
		*b = ((x + (2 * y)) - (c * 4)) / sqrt(6);
	}

	*a += data->start_point;
	*b += data->start_point;
}

void	rotate_map(t_fdf *data, int count_points, t_point *p, int height_multiplier)
{
	int i;

	i = 0;
	while (i < count_points)
	{
		rotate_point(data, &(p[i].x), &(p[i].y), (p[i].z * height_multiplier));
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
		while(column < data->c)
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
	if (button == 99)
		set_color(data);
	if (button == 27 || button == 45 || button == 24 || button == 43)
		change_height(button, data);
	if (button == 123 || button == 65361 || button == 124 || button == 65363)
		map_rotate(button, data);
	if (button == 126 || button == 65362 || button == 125 || button == 65364)
		change_position(button, data);
	if (button == 65307 || button == 53)
		exit(1);
	return (0);
}

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
