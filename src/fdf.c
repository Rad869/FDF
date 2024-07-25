/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:00 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/24 15:18:41 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	key_handler(int key, t_fdf *data)
{
	ft_printf("Press key :%d\nLen col : %d\n", key, data->len_col);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;
	int		X;
	int		Y;

	fdf = malloc(sizeof(t_fdf));
	fdf->ecart = 20;
	check_maps(argc, argv);
	read_entry(argv[1], fdf);
	fdf->mlx = mlx_init();
	mlx_get_screen_size(fdf->mlx, &X, &Y);
	fdf->win = mlx_new_window(fdf->mlx, X / 2, Y / 2, "First Windows");
	//breseham(10, 10, 200, 400, fdf);
	draw(fdf);
	mlx_key_hook(fdf->win, key_handler, fdf);
	mlx_loop(fdf->mlx);
	
}