/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:15:08 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/28 05:44:41 by rrabeari         ###   ########.fr       */
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

void	transform_origine(float *x, float *y, int *z, t_fdf *data)
{
	compute_origine(data);
	*z *= data->ecart;
	*x *= data->ecart;
	*y *= data->ecart;
	isometric(x, y, *z, data);
}

void	transform_translation(float *x, float *y, t_fdf *data)
{
	*x += data->x_pos;
	*y += data->y_pos;
}

void	breseham(point depart, point arriver, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		maximum;

	depart.z = data->z_matrix[(int) depart.y][(int) depart.x];
	arriver.z = data->z_matrix[(int) arriver.y][(int) arriver.x];
	transform_origine(&depart.x, &depart.y, &depart.z, data);
	transform_origine(&arriver.x, &arriver.y, &arriver.z, data);
	transform_translation(&depart.x, &depart.y, data);
	transform_translation(&arriver.x, &arriver.y, data);
	x_step = arriver.x - depart.x;
	y_step = arriver.y - depart.y;
	maximum = max(module(x_step), module(y_step));
	x_step /= maximum;
	y_step /= maximum;
	while ((int)(depart.x - arriver.x) || (int)(depart.y - arriver.y))
	{
		mlx_pixel_put(data->mlx, data->win, depart.x, depart.y, depart.color);
		depart.x += x_step;
		depart.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	point	depart;
	point	arriver;

	depart.y = 0;
	while (depart.y < data->len_row)
	{
		depart.x = 0;
		while (depart.x < data->len_col)
		{
			if (depart.x < data->len_col - 1)
			{
				arriver.x = depart.x + 1;
				arriver.y = depart.y;
				depart.color = data->c_matrix[(int) depart.y][(int) depart.x];
				arriver.color = data->c_matrix[(int) depart.y][(int) arriver.x];
				breseham(depart, arriver, data);
			}
			if (depart.y < data->len_row - 1)
			{
				arriver.x = depart.x;
				arriver.y = depart.y + 1;
				depart.color = data->c_matrix[(int) depart.y][(int) depart.x];
				arriver.color = data->c_matrix[(int) arriver.y][(int) depart.x];
				breseham(depart, arriver, data);
			}
			depart.x++;
		}
		depart.y++;
	}
}
