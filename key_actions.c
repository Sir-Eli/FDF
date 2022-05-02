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

void	set_color(t_fdf *data, int button)
{
	if (data->color == 1)
	{
		data->color_h = data->color_h * 3;
		data->color_l = data->color_l * 3;
	}
	if (data->color == 2)
	{
		data->color_h = data->color_h / 2;
		data->color_l = data->color_l / 2;
	}
	if (++data->color == 3)
		data->color = 1;
	if (button == 111)
	{
		data->color_h = 0xff00aa;
		data->color_l = 0x0859c6;
	}
}

void	change_map_size(int button, t_fdf *data)
{
	if (button == 6 || button == 122)
		data->size = data->size + 0.6;
	if (button == 7 || button == 120)
		data->size = data->size - 0.6;
}

void	change_height(int button, t_fdf *data)
{
	if (data->rotate == 1)
	{
		if (button == 27 || button == 45)
			data->height -= 1;
		if (button == 24 || button == 43)
			data->height += 1;
	}
	else
		data->tip_to_user = 1;
}

void	map_rotate(t_fdf *data)
{
	if (data->rotate == 1)
	{
		data->rotate = 0;
		data->where_x -= 200;
		data->where_y += 80;
	}
	else
	{
		data->rotate = 1;
		data->where_x += 200;
		data->where_y -= 80;
	}
}

void	change_position(int button, t_fdf *data)
{
	if (button == 126 || button == 65362)
		data->where_y -= 10;
	if (button == 125 || button == 65364)
		data->where_y += 10;
	if (button == 123 || button == 65361)
		data->where_x -= 10;
	if (button == 124 || button == 65363)
		data->where_x += 10;
}
