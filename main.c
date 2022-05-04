/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/04 16:27:04 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_program(t_fdf *data, char *file)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1500, 1200, "fdf");
	data->start_point = 360;
	data->height = 1.2;
	data->rotate = 0;
	set_color(data, 111);
	data->amount_points = data->c * data->r;
	data->size = 36;
	data->tip_to_user = 0;
	data->where_x = 0;
	data->where_y = 0;
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
	ft_bzero(data, sizeof(t_fdf));
	map_size(argv[1], &data->c, &data->r);
	start_program(data, argv[1]);
	mlx_hook(data->win, 2, 1L << 0, key, data);
	/*mlx_key_hook(data->win, &key, data);*/
	mlx_loop(data->mlx);
}

/*int main(int argc, char **argv)
{
	char line[25] = "10  11  0  11  5  0";
	char **splitted;
	int c;
	int r;
	int i;

	map_size(argv[1], &c, &r);
	printf("c: %d and c: %d", c, r);
	i = 0;
	splitted = ft_strsplit(line, '.');
	while (splitted[i] != NULL)
	{
		ft_putstr(splitted[i]);
		ft_putchar('\n');
		i++;
	}

}*/

/*void	print_map(int *arr, int r, int c)
{
	int	keep_track_cols = 0;
	int	keep_track_rows = 0;
	int	i = 0;

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
	}*/
