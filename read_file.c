/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:34:55 by esirnio           #+#    #+#             */
/*   Updated: 2022/04/27 18:02:08 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(char *file, int *c, int *r)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("-- open failed, try another file --");
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
		free(line);
	}
	close(fd);
}

void	is_value_valid(int value, char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (!(ft_isdigit(string[i])) && string[i] != '-')
			error("No good character");
		i++;
	}
	if (value < - 2000 || value > 2000 )
		error("Number too big or small");
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	data->arr = (int *)malloc(sizeof(int) * data->amount_points);
	ft_bzero(data->arr, (sizeof(int) * data->amount_points));
	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		free(line);
		while (split[j])
		{
			data->arr[i] = ft_atoi(split[j]);
			is_value_valid(data->arr[i], split[j]);
			i++;
			j++;
		}
		j = 0;
 		ft_free_array(split);
	}
	close(fd);
}
