/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/14 17:41:21 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
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

void	draw_map(fdf *data)
{
	int	rows;
	int	cols;
	int	value_arr;

	value_arr = 0;
	rows = 0;
	cols = 0;
	data->height = data->r;
	data->width = data->c;
	data->x = data->width / 2;
	data->y = data->height / 3;
	printf("\n\nIN DRAW FUNCTION\n\n");
	while(rows < data->r)
	{

		while(cols < data->c)
		{
			printf("%3d", data->arr[value_arr]);
			if (data->arr[value_arr] == 0)
			{
				draw_line(data->mlx, data->win, data->x, data->y, data->x + 10, data->y, 0xCF2FAF);
				draw_line(data->mlx, data->win, data->x, data->y, data->x, data->y + 20, 0xCF2FAF);
			}
			else
			{
				draw_line(data->mlx, data->win, data->x, data->y, data->x + 10, data->y, 0xCFFFAF);
				draw_line(data->mlx, data->win, data->x, data->y, data->x, data->y + 20, 0xCFFFAF);
			}
			data->x = data->x + 20;
			value_arr++;
			cols++;
		}
		printf("\n");
		data->x = data->width / 2;
		data->y = data->y + 20;
		cols = 0;
		rows++;
	}
}
//	mlx_hook(data->win, 2, 1L<<0, close, &data);