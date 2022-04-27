
#include "fdf.h"

void	rotate_point(t_fdf *data, float *a, float *b, float c)
{
	int	x;
	int	y;

	if (data->rotate == 1)
	{
		x = *a;
		y = *b;
		*a = (x - y) / sqrt(2);
		*b = ((x + (2 * y)) - (c * 4)) / sqrt(6);
	}

	*a += data->start_point;
	*b += data->start_point;
}

void	rotate_map(t_fdf *data, int count_points, t_point *p, int height_multiplier)
{
	int i;

	i = 0;
	while (i < count_points)
	{
		rotate_point(data, &(p[i].x), &(p[i].y), (p[i].z * height_multiplier));
		i++;
	}
}
void	set_points2(t_fdf *data, t_point *points)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
	//ft_bzero(points, (sizeof(t_point) * 8140));
	while (row < data->r)
	{
		while(column < data->c)
		{
			//printf("i: %d\n", i);
			//printf("%f\n", points[i].y);
			printf("column: %d row: %d i: %d, data->c: %d, data->r: %d\n", column, row, i, data->c, data->r);
			points[i].x = column + 1;
			points[i].y = row + 1;
			points[i].z = data->arr[i];
			printf("set_points: i: %d, p[i].x : %f, p[i].y : %f, p[i].z : %f  \n\n", i, points[i].x, points[i].y, points[i].z);
			i++;
			column++;
		}
		row++;
		column = 0;
	}
}

void	set_points(t_fdf *data, t_point *points)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
	//ft_bzero(points, (sizeof(t_point) * 50000));
	while (row < data->r)
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

void	set_color(t_fdf *data, char color)
{
	if (color == 3)
	{
		data->color_h = 0x66233F;
		data->color_l = 0x118FBF;
	}
	if (color == 4)
	{
		data->color_h = 0x222FAF;
		data->color_l = 0xE1F2FA;
	}
		if (color == 5)
	{
		data->color_h = 0x222F5F;
		data->color_l = 0xA42FAF;
	}
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

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
