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
	ft_putnbr(button);
	if (button == 65362)
		data->size = data->size + 0.2;
	if (button == 65364)
		data->size = data->size - 0.2;
	if (button == 'b'|| button == 'm' || button == 'n')
		set_color(data, button);
	if (button == 45)
		data->height_multiplier -= 1;
	if (button == 65506)
		data->height_multiplier += 1;
	if (button == 44)
		data->rotate = 1;
	if (button == 46)
		data->rotate = 0;
	if (button == 65361)
		data->start_point -= 10;
	if (button == 65363)
		data->start_point += 10;
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
		data->color_h = 0x66233F;
		data->color_l = 0x118FBF;
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

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	t_point	p[50000];

	if (argc == 1)
		error("File missing");
	else if (argc > 2)
		error("Too many files");
	ft_bzero(p, 50000);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	ft_bzero(data, sizeof(t_fdf));
	map_size(argv[1], &data->c, &data->r);
	start(data);
	read_file(argv[1], data);
	start(data);
	draw_map(data, p);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->mlx);

	free(data->arr);
	system("leaks fdf");
}
