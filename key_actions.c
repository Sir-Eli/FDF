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

void	new_drawing(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (data->warning == 1)
		mlx_string_put(data->mlx, data->win, 400, 250, 0xFF00AA, \
			"------------Rotate first with arrow to left, then change height :)------------");
	data->warning = 0;
	text(data);
	set_points(data, data->p);
	rotate_map(data, data->amount_points, data->p, data->height_multiplier);
	draw_map(data, data->p);
}

void	set_color(t_fdf *data)
{
	data->color++;
	if (data->color == 4)
		data->color = 1;
	if (data->color == 1)
	{
		data->color_h = 0x66233F;
		data->color_l = 0x118FBF;
	}
	if (data->color == 2)
	{
		data->color_h = 0xa22FAF;
		data->color_l = 0x11F2FA;
	}
	if (data->color == 3)
	{
		data->color_h = 0x062F5F;
		data->color_l = 0x742FAF;
	}
	new_drawing(data);
}

void	change_map_size(int button, t_fdf *data)
{
	if (button == 6 || button == 122)
		data->size = data->size + 0.6;
	if (button == 7 || button == 120)
		data->size = data->size - 0.6;
	new_drawing(data);
}

void change_height(int button, t_fdf *data)
{
	if (data->rotate == 1)
	{
		if (button == 27 || button == 45)
			data->height_multiplier -= 1;
		if (button == 24 || button == 43)
			data->height_multiplier += 1;
	}
	else
		data->warning = 1;
	new_drawing(data);
}

void	map_rotate(int button, t_fdf *data)
{
	if (button == 123 || button == 65361)
		data->rotate = 1;
	if (button == 124 || button == 65363)
		data->rotate = 0;
	new_drawing(data);
}

void	change_position(int button, t_fdf *data)
{
	if (button == 126 || button == 65362)
		data->start_point -= 10;
	if (button == 125 || button == 65364)
		data->start_point += 10;
	new_drawing(data);
}
