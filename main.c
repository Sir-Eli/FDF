/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/13 13:56:24 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	start_program(t_fdf *data, char *file)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1500, 1200, "fdf");
	data->start_point = 360;
	data->height = 1.2;
	data->rotate = 0;
	set_color(data, 111);
	data->amount_points = data->c * data->r;
	data->size = 3600 / ((float)data->amount_points / 2);
	data->tip_to_user = 0;
	data->where_x = 0;
	data->where_y = 0;
	data->arr = (int *)malloc(sizeof(int) * data->amount_points);
	if (!data->arr)
		error("malloc failed");
	ft_bzero(data->arr, (sizeof(int) * data->amount_points));
	text(data);
	read_file(file, data);
	set_points(data, data->p);
	rotate_map(data, data->amount_points, data->p, data->height);
	draw_map(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error("Usage: ./fdf <filename>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		error("malloc failed");
	ft_bzero(data, sizeof(t_fdf));
	map_size(argv[1], &data->c, &data->r);
	start_program(data, argv[1]);
	mlx_hook(data->win, 2, 1L << 0, key, data);
	mlx_loop(data->mlx);
}
