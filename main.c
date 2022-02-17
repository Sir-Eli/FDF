/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/02/14 15:14:38 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		create_map(fd);
		close(fd);
	}
	else
	{
		ft_putstr("error");
	}


}

// void	*mlx = mlx_init();
// void	*win = mlx_new_window(mlx, 1000, 1000, "FDF");
//mlx_loop(mlx);