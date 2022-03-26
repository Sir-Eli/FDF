/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/17 18:11:34 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*print_map(data.arr, data.r, data.c);
void	print_map(int *arr, int r, int c)
{
	int keep_track_cols = 0;
	int keep_track_rows = 0;
	int i = 0;

	while (keep_track_rows < r)
	{
		printf("%3d", arr[i]);
		keep_track_cols++;
		if (keep_track_cols == c)
		{
			printf("\n");
			keep_track_rows++;
			keep_track_cols = 0;
			if (keep_track_rows == r)
				break ;
		}
		i++;
	}
}*/

int	key(int button, t_fdf *data)
{
	(void)data;
	if (button == 53 || button == 113)
		exit (1);
	return (1);
}

//ft_putnbr(button); find value for key inside key function
void	set_points(t_fdf *data, t_point *points)
{
	int	i;
	int	row;
	int	column;

	data->size = 20;
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

int	main(int argc, char **argv)
{
	t_fdf	data;
	t_point	p[50000];

	(void)argc;
	map_size(argv[1], &data.c, &data.r);
	data.arr = (int *)malloc(sizeof(int) * (data.r * data.c) + 100);
	ft_bzero(data.arr, (sizeof(int) * (data.r * data.c) + 100));
	data.win_height = 1000;
	data.win_width = 1000;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_height, data.win_width, "fdf");
	fill_array(argv[1], data.arr);
	data.amount_points = data.c * data.r;
	set_points(&data, p);
	draw_map(&data, p);
	
	mlx_key_hook(data.win, &key, &data);
	mlx_loop(data.mlx);

	free(data.arr);
}
