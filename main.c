/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/14 17:44:06 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

int	key(int button, fdf *data)
{
	(void)data;
	if (button == 53)
		exit (1);
	return (1);
}

//ft_putnbr(button); find value for key inside key function

int	main(int argc, char **argv)
{
	fdf	data;

	(void)argc;
	map_size(argv[1], &data.c, &data.r);
	data.arr = (int *)malloc(sizeof(int) * (data.r * data.c) + 100);
	ft_bzero(data.arr, (sizeof(int) * (data.r * data.c) + 100));
	data.win_height = 1000;
	data.win_width = 1000;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_height, data.win_width, "fdf");
	fill_array(argv[1], data.arr);
	print_map(data.arr, data.r, data.c);
	draw_map(&data);
	mlx_key_hook(data.win, &key, &data);
	mlx_loop(data.mlx);
	free(data.arr);
}
