/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:15:08 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/25 11:19:10 by rrabeari         ###   ########.fr       */
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
	float	x_tmp;
	float	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = x_tmp * cos (PI / 4) + y_tmp * cos(PI / 4 + 2) - z * cos(PI / 4 - 2);
	*y = x_tmp * sin (PI / 4) + y_tmp * sin(PI / 4 + 2) + z * sin(PI / 4 - 2);
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
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += 300;
	y += 150;
	x1 += 300;
	y1 += 150;
	x_step = x1 - x;
	y_step = y1 - y;
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