/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:15:08 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/24 15:43:58 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define MAX1(a, b) (a > b ? a : b)

float	module(float var)
{
	if (var < 0)
		return (-var);
	return (var);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	breseham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		maximum;
	int		z;
	int		z1;


	z = data->z_matrix[(int) y][(int) x];
	z1 = data->z_matrix[(int) y1][(int) x1];
	x *= data->ecart;
	y *= data->ecart;
	x1 *= data->ecart;
	y1 *= data->ecart;
	//z1 = data->z_matrix[(int) y1][(int) x1];
	x_step = x1 - x;
	y_step = y1 - y;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	maximum = MAX1(module(x_step), module(y_step));
	x_step /= maximum;
	y_step /= maximum;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->len_row)
	{
		x = 0;
		while (x < data->len_col)
		{
			if (x < data->len_col - 1)
				breseham(x, y, x + 1, y, data);
			if (y < data->len_row - 1)
				breseham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}