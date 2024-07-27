/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fdf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:25:36 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/27 21:09:23 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	compute_origine(t_fdf *data)
{
	data->x_pos = 0;
	data->y_pos = 0;
	if (data->x_min < 0)
		data->x_pos = -data->x_min;
	if (data->y_min < 0)
		data->y_pos = -data->y_min;
	data->x_pos += (data->win_x - (data->x_max - data->x_min)) / 2;
	data->y_pos += (data->win_y - (data->y_max - data->y_min)) / 2;
}

void	choose_min_max(float x, float y, t_fdf *data)
{
	if (x < data->x_min)
		data->x_min = x;
	if (x > data->x_max)
		data->x_max = x;
	if (y < data->y_min)
		data->y_min = y;
	if (y > data->y_max)
		data->y_max = y;
}

void	get_min_max(t_fdf *data)
{
	float	x;
	float	y;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	compute_origine(data);
	while (j < data->len_row)
	{
		i = 0;
		while (i < data->len_col)
		{
			x = i;
			y = j;
			z = data->z_matrix[j][i];
			transform_origine(&x, &y, &z, data);
			choose_min_max(x, y, data);
			i++;
		}
		j++;
	}
}

void	compute_ecart(t_fdf *data)
{
	data->ecart = 1;
	get_min_max(data);
	while ((data->x_max - data->x_min) < data->win_x - 100 \
		&& (data->y_max - data->y_min) < data->win_y - 200)
	{
		data->ecart++;
		get_min_max(data);
	}
	get_min_max(data);
}

t_fdf	*initialize_fdf(int argc, char *argv[])
{
	t_fdf	*value;

	check_maps(argc, argv);
	value = malloc(sizeof(t_fdf));
	read_entry(argv[1], value);
	value->mlx = mlx_init();
	mlx_get_screen_size(value->mlx, &value->win_x, &value->win_y);
	value->theta = PI / 3;
	value->phi = PI / 3;
	value->x_min = value->win_x;
	value->y_min = value->win_y;
	value->x_max = 0;
	value->y_max = 0;
	compute_ecart(value);
	compute_origine(value);
	value->win_y -= 100;
	value->win = mlx_new_window(value->mlx, value->win_x, value->win_y, "fdf");
	return (value);
}
