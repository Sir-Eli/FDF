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

void	rotate_point(float *a, float *b, float c)
{
	int	x;
	int	y;

	x = *a;
	y = *b;
	*a = (x - y) / sqrt(2);
	*b = ((x + (2 * y)) - (c * 4)) / sqrt(6);

	*a += 260;
	*b += 260;
}

void	rotate_map(int count_points, t_point *p, int height_multiplier)
{
	int i;

	i = 0;
	while (i < count_points)
	{
		rotate_point(&(p[i].x), &(p[i].y), (p[i].z * height_multiplier));
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
	while (i < data->amount_points)
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



void	draw_map(t_fdf *data, t_point *p)
{

	int	i;
	int row;
	int col;

	data->height_multiplier = 2;
	i = 0;
	col = 0;
	row = 1;
	set_points(data, p);
	rotate_map(data->amount_points, p, data->height_multiplier);
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
