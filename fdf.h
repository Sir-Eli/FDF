/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:58 by esirnio           #+#    #+#             */
/*   Updated: 2022/04/27 16:12:27 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "mlx.h"
#include <math.h>


typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}		t_point;

typedef struct s_fdf
{
	int		c;
	int		r;
	int		amount_points;
	int		*arr;
	void	*mlx;
	void	*win;
	int		color_h;
	int		color_l;
	int		height_multiplier;
	int		start_point;
	int		rotate;
	t_point	p[500000];
	float	size;
}		t_fdf;

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void	error(char *str);
void	start(t_fdf *data);
int		get_next_line(const int fd, char **line);
void	rows(char *file, int *r);
void	map_size(char *file, int *c, int *r);
void	read_file(char *file, t_fdf *data);
int	draw_map(t_fdf *data, t_point *p);
void	set_points(t_fdf *data, t_point *points);
void	set_color(t_fdf *data, char color);
void	text(t_fdf *data);
void	rotate_map(t_fdf *data, int count_points, t_point *p, int height_multiplier);
void	rotate_point(t_fdf *data, float *a, float *b, float c);
#endif