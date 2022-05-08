/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:58 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/04 16:17:11 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

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
	int		color;
	int		color_h;
	int		color_l;
	float	height;
	int		start_point;
	int		rotate;
	int		tip_to_user;
	t_point	p[500000];
	float	size;
	int		where_x;
	int		where_y;
}		t_fdf;

int		key(int button, t_fdf *data);
void	set_color(t_fdf *data, int button);
void	new_drawing(t_fdf *data);
void	draw_line(t_fdf *data, int start_xy[2], int end_xy[2], int color);
void	change_map_size(int button, t_fdf *data);
void	map_rotate(t_fdf *data);
void	change_height(int button, t_fdf *data);
void	change_position(int button, t_fdf *data);
void	error(char *str);
void	start(t_fdf *data, char *file);
int		get_next_line(const int fd, char **line);
void	rows(char *file, int *r);
void	map_size(char *file, int *c, int *r);
void	read_file(char *file, t_fdf *data);
void	draw_map(t_fdf *data);
void	set_points(t_fdf *data, t_point *points);
void	text(t_fdf *data);
void	rotate_map(t_fdf *data, int count_points, t_point *p, int height);
void	rotate_point(t_fdf *data, float *a, float *b, float c);
#endif