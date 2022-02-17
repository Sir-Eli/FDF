/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:58 by esirnio           #+#    #+#             */
/*   Updated: 2022/02/14 16:38:44 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

#define FDF_H

#include <sys/stat.h>
#include <mlx.h>
#include <fcntl.h>
# include "libft/libft.h"
typedef struct s_point
{
	int	rows;
	int	cols;
	int	color;
}	fdf_map;


#endif