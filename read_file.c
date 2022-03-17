/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:34:55 by esirnio           #+#    #+#             */
/*   Updated: 2022/03/17 14:27:30 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(char *file, int *c, int *r)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	*c = 0;
	*r = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (*c == 0)
		{
			while (line[i])
			{
				if (line[i] == ' ' || (i != 0 && line [i - 1] != ' '))
				{
					i++;
					continue ;
				}
				i++;
				(*c)++;
			}
		}
		(*r)++;
		printf("%p", line);
		free(line);
	}
	close(fd);
}

void	fill_array(char *file, int *arr)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		printf("%p", line);
		free(line);
		while (split[j])
		{
			arr[i] = ft_atoi(split[j]);
			i++;
			j++;
		}
		j = 0;
	}
	printf("%p", split);
	ft_free_array(split);
	close(fd);
}
