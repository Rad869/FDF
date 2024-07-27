/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:25:36 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/27 15:14:40 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	compute_origine(t_fdf *data)
{
	data->x_pos = data->win_x / 2 - data->len_col * data->ecart / 2;
	data->y_pos = data->win_y / 2 - data->len_row * data->ecart / 2;
}


t_fdf	*initialize_fdf(int argc, char *argv[])
{
	t_fdf	*value;

	check_maps(argc , argv);
	value = malloc(sizeof(t_fdf));
	read_entry(argv[1], value);
	value->mlx = mlx_init();
	mlx_get_screen_size(value->mlx, &value->win_x, &value->win_y);
	value->theta = PI / 3;
	value->phi = PI / 3;
	value->ecart = 20;
	value->win = mlx_new_window(value->mlx, value->win_x, value->win_y, "fdf");
	compute_origine(value);
	return (value);
}