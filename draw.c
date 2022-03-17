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

void	rotate_shape(float *a, float *b)
{
	/*int	x;
	int	y;

	x = *a;
	y = *b;
	*a = (x - y) / sqrt(2);
	*b = ((x + (2 * y)) - (c * 4)) / sqrt(6);*/

	*a += 100;
	*b += 100;
}

void	draw_map(t_fdf *data, t_point *p)
{
	int	i;
	int row;
	int col;
	float ty;
	float tx;

	i = 0;
	col = 0;
	row = 1;
	while (row < data->r)
	{
		while (col < data->c)
		{
			rotate_shape(&(p[i].x), &(p[i].y));
			//rotate_shape(&(p[i + 1].x), &(p[i + 1].y));
			ty = p[row * data->c + col].x;
			tx = p[row * data->c + col].y;
			rotate_shape(&tx, &ty);

			printf("%3d", data->arr[i]);
			//draw_line(data->mlx, data->win, p[i].x, p[i].y, p[i + 1].x, p[i + 1].y, 0xCF2FAF);


			
			draw_line(data->mlx, data->win, p[i].x, p[i].y, tx, ty, 0xCFFFAF);

			
			col++;
			i++;
		}
		row++;
		col = 0;
	}
/*	int	rows;
	int	cols;
	int	value_arr;
	float line_length;
	int end_x;
	int	end_y;

	line_length = 30;
	value_arr = 0;
	rows = 0;
	cols = 0;
	end_x = data->x + line_length;
	end_y = data->y + line_length;
	data->height = data->r;
	data->width = data->c;
	data->x = data->width;
	data->y = data->height;
	printf("\n\nIN DRAW FUNCTION\n\n");
	while(rows <= data->r)
	{

		while(cols < data->c)
		{
			//rotate_shape(&data->x, &data->y, data->arr[value_arr]);
			//rotate_shape(&end_x, &end_y, data->arr[value_arr]);
			printf("%3d", data->arr[value_arr]);
			if (data->arr[value_arr] == 0)
			{
				//rotate_shape(&data->x, &data->y, data->arr[value_arr]);
				//rotate_shape(&end_x, &data->y, data->arr[value_arr]);
				draw_line(data->mlx, data->win, data->x, data->y, end_x, data->y, 0xCF2FAF);
				if (rows < data->r)
				{
					//rotate_shape(&data->x, &end_y, data->arr[value_arr]);
					draw_line(data->mlx, data->win, data->x, data->y, data->x, end_y, 0xCF2FAF);
				}
			}
			else
			{
				//rotate_shape(&data->x, &data->y, data->arr[value_arr]);
				//rotate_shape(&end_x, &data->y, data->arr[value_arr]);
				draw_line(data->mlx, data->win, data->x, data->y, end_x, data->y, 0xCFFFAF);
				if (rows < data->r)
				{
					//rotate_shape(&data->x, &end_y, data->arr[value_arr]);
					draw_line(data->mlx, data->win, data->x, data->y, data->x, end_y, 0xCFFFAF);
				}
			}
			data->x = data->x + line_length;
			end_y = data->y + line_length;
			end_x = data->x + line_length;
			value_arr++;
			cols++;
		}
		printf("\n");
		data->x = data->width;
		data->y = data->y + line_length;
		end_x = data->x + line_length;
		end_y = data->y + line_length;
		cols = 0;
		rows++;
	}*/
}
//	mlx_hook(data->win, 2, 1L<<0, close, &data);
