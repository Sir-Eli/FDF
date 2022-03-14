/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:58 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/14 17:28:17 by esirnio          ###   ########.fr       */
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
#include "mlx.h"
#include <math.h>

typedef struct
{
	int		c;
	int		r;
	int		*arr;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		x;
	int		y;
	int		win_height;
	int		win_width;
}		fdf;

int		get_next_line(const int fd, char **line);
void	rows(char *file, int *r);
void	map_size(char *file, int *c, int *r);
void	fill_array(char *file, int *arr);
void	draw_map(fdf *data);

#endif