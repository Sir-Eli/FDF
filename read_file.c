/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:34:55 by esirnio           #+#    #+#             */
/*   Updated: 2022/05/04 16:30:49 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_cols(char *line)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || (i != 0 && line [i - 1] != ' '))
		{
			i++;
			continue ;
		}
		i++;
		length++;
	}
	return (length);
}

void	map_size(char *file, int *c, int *r)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("-- open failed, try another file --");
	*c = 0;
	*r = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			error("we do not need newlines here");
		if (*c == 0)
			line_length = count_cols(line);
		*c = count_cols(line);
		if (line_length != *c)
			error("lines different length");
		(*r)++;
		free(line);
	}
	close(fd);
}

void	is_value_valid(int value, char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-')
		i++;
	while (string[i] != '\0')
	{
		if (!(ft_isdigit(string[i])))
			error("No good character");
		i++;
	}
	if (value < -11000 || value > 9000)
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
	if (fd < 0)
		error("open failed");
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		split = ft_strsplit(line, ' ');
		free(line);
		while (j < data->c)
		{
			data->arr[i] = ft_atoi(split[j]);
			is_value_valid(data->arr[i], split[j]);
			i++;
			j++;
		}
		ft_free_array(split);
	}
	close(fd);
}
