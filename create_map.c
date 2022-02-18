/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:15:10 by esirnio           #+#    #+#             */
/*   Updated: 2022/02/18 12:51:08 by esirnio          ###   ########.fr       */
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
	int		r;
	char	*line;

	r = 0;
	while (r < specs->rows)
	{
		get_next_line()
	}
}

void	create_map(char *file)
{
	int		**map;
	fdf_map	*specs;

	specs->rows = 0;
	specs->cols = 0;
	count_size(fd, specs);
	map = (int **)malloc((specs->rows + 1) * (specs->cols + 1)); //

	fill_map(specs, map);
}

//aloit vaihtaa niin etta et avaa filua mainissa vaan lahetat suoraa create_mapille