/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/17 18:18:42 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	//printf("begx: %d, begy: %d, endx: %d, endy: %d\n", beginX, beginY, endX, endY);
	double deltaX = endX - beginX; //-1000
	double deltaY = endY - beginY; //-600
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;//-3,125
	deltaY /= pixels;//-1,875
	double pixelX = beginX;//1000
	double pixelY = beginY;//600
	while (pixels)//320
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

void	start(t_fdf *data)
{
	data->start_point = 360;
	data->height_multiplier = 2;
	data->rotate = 1;
	set_color(data, 'm');
	data->amount_points = data->c * data->r;
	data->size = data->amount_points / 20;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "fdf");
}

void	draw_map(t_fdf *data, t_point *p)
{

	int	i;
	int row;
	int col;

	i = 0;
	col = 0;
	row = 1;
	text(data);
	set_points(data, p);
	rotate_map(data, data->amount_points, p, data->height_multiplier);
	while (row <= data->r)
	{
		while (col < data->c)
		{
			if (col != data->c - 1)
			{
				if (p[i].z == 0)
					draw_line(data->mlx, data->win, p[i].x, p[i].y, p[i + 1].x, p[i + 1].y, data->color_l);
				if (p[i].z > 0)
					draw_line(data->mlx, data->win, p[i].x, p[i].y, p[i + 1].x, p[i + 1].y, data->color_h);
			}
			if (row < data->r)
			{
				if (p[i].z == 0)
					draw_line(data->mlx, data->win, \
						p[i].x, p[i].y, p[row * data->c + col].x, p[row * data->c + col].y, data->color_l);
				if (p[i].z > 0)
					draw_line(data->mlx, data->win, \
						p[i].x, p[i].y, p[row * data->c + col].x, p[row * data->c + col].y, data->color_h);
			}
				//draw_line(data->mlx, data->win, 
				//p[i].x, p[i].y, p[row * data->c + col].x, p[row * data->c + col].y, 0x442FAF);
			col++;
			i++;
		}
		row++;
		col = 0;
	}

}
//	mlx_hook(data->win, 2, 1L<<0, close, &data);
