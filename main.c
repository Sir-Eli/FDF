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

int	key(int button, t_fdf *data, t_point *p)
{
	(void)data;
	(void)p;
	ft_putnbr(button);
	if (button == 65362)
		data->size = data->size + 5;
	if (button == 65364)
		data->size = data->size - 5;
	if (button == 'b')
		set_color(data, 'b');
	if (button == 'm')
		set_color(data, 'm');
	if (button == 'n')
		set_color(data, 'n');
	if (button == 'v' || button == 53 || button == 113)
		exit(1);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, p);
	return (1);
}
void	set_color(t_fdf *data, char color)
{
	if (color == 'm')
	{
		data->color_h = 0xFF2FAF;
		data->color_l = 0xE12F2F;
	}
	if (color == 'b')
	{
		data->color_h = 0x222FAF;
		data->color_l = 0xE12FAF;
	}
		if (color == 'n')
	{
		data->color_h = 0x222F5F;
		data->color_l = 0xA42FAF;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	t_point	p[50000];

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	set_color(data, 'm');
	map_size(argv[1], &data->c, &data->r);
	data->amount_points = data->c * data->r;
	data->size = data->amount_points / 200;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "fdf");
	read_file(argv[1], data);
	//print_map(data.arr, data.r, data.c);
	draw_map(data, p);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->mlx);

	free(data->arr);
	system("leaks fdf");
}
