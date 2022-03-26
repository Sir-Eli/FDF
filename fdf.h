/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:58 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/17 18:14:38 by esirnio          ###   ########.fr       */
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

typedef struct s_fdf
{
	int		c;
	int		r;
	int		amount_points;
	int		*arr;
	void	*mlx;
	void	*win;
	int		color;
	int		height_multiplier;
	int		win_height;
	int		win_width;
	float	size;
}		t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}		t_point;

int		get_next_line(const int fd, char **line);
void	rows(char *file, int *r);
void	map_size(char *file, int *c, int *r);
void	fill_array(char *file, int *arr);
void	draw_map(t_fdf *data, t_point *p);

#endif