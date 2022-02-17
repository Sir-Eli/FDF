/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:15:10 by esirnio           #+#    #+#             */
/*   Updated: 2022/02/14 17:04:55 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_size(int fd, fdf_map *specs)
{
	int		ret;
	char	*line;

	ret = 1;
	while(ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			specs->rows++;
			if (specs->cols != ft_strlen(line))
				exit;//bad exit do
			specs->cols = ft_strlen(line);
			free(line);
		}
	}
}

void	fill_map(fdf_map *specs, int **map)
{
	
}

void	create_map(int fd)
{
	int		**map;
	fdf_map	*specs;

	count_size(fd, specs);
	map = (int **)malloc((specs->rows + 1) * (specs->cols + 1));
	fill_map(specs, map);
}