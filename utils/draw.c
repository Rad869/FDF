/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:15:08 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:23:00 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	float	x_tmp;
	float	y_tmp;
	float	theta;
	float	phi;

	x_tmp = *x;
	y_tmp = *y;
	theta = data->theta;
	phi = data->phi;
	*x = x_tmp * cos(theta) - y_tmp * sin(theta);
	*y = x_tmp * sin(theta) * cos(phi) + \
		y_tmp * cos(theta) * cos(phi) - z * sin(phi);
}

void	breseham(point depart, point arr, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		maximum;

	depart.z = data->z_matrix[(int) depart.y][(int) depart.x];
	arr.z = data->z_matrix[(int) arr.y][(int) arr.x];
	transform_origine(&depart.x, &depart.y, &depart.z, data);
	transform_origine(&arr.x, &arr.y, &arr.z, data);
	transform_translation(&depart.x, &depart.y, data);
	transform_translation(&arr.x, &arr.y, data);
	x_step = arr.x - depart.x;
	y_step = arr.y - depart.y;
	maximum = max(module(x_step), module(y_step));
	x_step /= maximum;
	y_step /= maximum;
	while ((int)(depart.x - arr.x) || (int)(depart.y - arr.y))
	{
		my_mlx_pixel_put(data, depart.x, depart.y, \
			gradient_color(depart.color, arr.color, \
			1 - (arr.x - depart.x) / (x_step * maximum)));
		depart.x += x_step;
		depart.y += y_step;
	}
}

void	set_arriver(point depart, float x, float y, t_fdf *data)
{
	point	arr;

	arr.x = x;
	arr.y = y;
	arr.color = data->c_matrix[(int) arr.y][(int) arr.x];
	breseham(depart, arr, data);
}

void	draw(t_fdf *data)
{
	point	depart;

	depart.y = 0;
	while (depart.y < data->len_row)
	{
		depart.x = 0;
		while (depart.x < data->len_col)
		{
			depart.color = data->c_matrix[(int) depart.y][(int) depart.x];
			if (depart.x < data->len_col - 1)
				set_arriver(depart, depart.x + 1, depart.y, data);
			if (depart.y < data->len_row - 1)
				set_arriver(depart, depart.x, depart.y + 1, data);
			depart.x++;
		}
		depart.y++;
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}
