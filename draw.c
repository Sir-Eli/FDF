/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/04 16:27:35 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *data, int start_xy[2], int end_xy[2], int color)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = end_xy[0] - start_xy[0];
	delta_y = end_xy[1] - start_xy[1];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start_xy[0];
	pixel_y = start_xy[1];
	while (pixels)
	{
		mlx_pixel_put(data->mlx, data->win, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	draw_row(t_fdf *data, int cur)
{
	int	end_xy[2];
	int	start_xy[2];

	start_xy[0] = data->p[cur].x;
	start_xy[1] = data->p[cur].y;
	end_xy[0] = data->p[cur + 1].x;
	end_xy[1] = data->p[cur + 1].y;
	if (data->p[cur].z != 0)
		draw_line(data, start_xy, end_xy, \
			data->color_h + (data->p[cur].z * 3400));
	else if (data->p[cur + 1].z != 0)
		draw_line(data, start_xy, end_xy, \
			data->color_h + (data->p[cur + 1].z * 3400));
	else
		draw_line(data, start_xy, end_xy, data->color_l);
}

void	draw_col(t_fdf *data, int cur, int row, int col)
{
	int	end_xy[2];
	int	start_xy[2];

	start_xy[0] = data->p[cur].x;
	start_xy[1] = data->p[cur].y;
	end_xy[0] = data->p[row * data->c + col].x;
	end_xy[1] = data->p[row * data->c + col].y;
	if (data->p[cur].z != 0)
		draw_line(data, start_xy, end_xy, \
			data->color_h + (data->p[cur].z * 3400));
	else if (data->p[cur + data->c].z != 0)
		draw_line(data, start_xy, end_xy, \
			data->color_h + (data->p[cur + data->c].z * 3400));
	else
		draw_line(data, start_xy, end_xy, data->color_l);
}

void	draw_map(t_fdf *data)
{
	int	cur_point;
	int	row;
	int	col;

	cur_point = 0;
	col = 0;
	row = 1;
	while (row <= data->r)
	{
		while (col < data->c)
		{
			if (col != data->c - 1)
				draw_row(data, cur_point);
			if (row < data->r)
				draw_col(data, cur_point, row, col);
			col++;
			cur_point++;
		}
		row++;
		col = 0;
	}
}

void	new_drawing(t_fdf *data)
{
	set_points(data, data->p);
	rotate_map(data, data->amount_points, data->p, data->height);
	mlx_clear_window(data->mlx, data->win);
	text(data);
	draw_map(data);
}
