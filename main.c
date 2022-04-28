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

void	start_program(t_fdf *data, char *file)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1500, 1200, "fdf");
	data->start_point = 360;
	data->height_multiplier = 2;
	data->rotate = 1;
	data->color = 1;
	data->color_h = 0x66233F;
	data->color_l = 0x118FBF;
	data->amount_points = data->c * data->r;
	data->size = 30;
	data->warning = 0;
	text(data);
	read_file(file, data);
	set_points(data, data->p);
	rotate_map(data, data->amount_points, data->p, data->height_multiplier);
	draw_map(data, data->p);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error("Usage: ./fdf <filename>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	ft_bzero(data, sizeof(t_fdf));
	map_size(argv[1], &data->c, &data->r);
	start_program(data, argv[1]);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->mlx);
}


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
