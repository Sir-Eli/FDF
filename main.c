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

int	key(int button, t_fdf *data)
{
	ft_putnbr(button);
	if (button == 6)
		data->size = data->size + 0.6;
	if (button == 7)
		data->size = data->size - 0.6;
	if (button == 3|| button == 4 || button == 5)
		set_color(data, button);
	if (button == 27)
		data->height_multiplier -= 1;
	if (button == 24)
		data->height_multiplier += 1;
	if (button == 123)
		data->rotate = 1;
	if (button == 124)
		data->rotate = 0;
	if (button == 126)
		data->start_point -= 10;
	if (button == 125)
		data->start_point += 10;
	if (button == 53)
		exit(1);
	mlx_clear_window(data->mlx, data->win);
	printf("hi");
	set_points(data, data->p);
	draw_map(data, data->p);
	return (0);
}
int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error("Usage: ./fdf <filename>");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	ft_bzero(data, sizeof(t_fdf));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1500, 1200, "fdf");
	map_size(argv[1], &data->c, &data->r);
	start(data);
	read_file(argv[1], data);
	set_points(data, data->p);
	draw_map(data, data->p);
	mlx_key_hook(data->win, &key, data);
	mlx_loop(data->mlx);
}
