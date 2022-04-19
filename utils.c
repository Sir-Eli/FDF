
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

void	set_points(t_fdf *data, t_point *points)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
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