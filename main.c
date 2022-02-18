/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:30 by esirnio           #+#    #+#             */
/*   Updated: 2022/02/18 12:51:19 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{

	if (argc == 2)
		create_map(argv[1]);
	else
	{
		ft_putstr("error");
	}


}

// void	*mlx = mlx_init();
// void	*win = mlx_new_window(mlx, 1000, 1000, "FDF");
//mlx_loop(mlx);