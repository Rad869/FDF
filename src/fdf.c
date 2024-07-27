/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:00 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/27 19:52:39 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	key_handler(int key, t_fdf *data)
{
	int	i;

	i =0;
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		while (i < data->len_row)
		{
			free(data->z_matrix[i]);
			free(data->c_matrix[i]);
			i++;
		}
		free(data->z_matrix);
		free(data->c_matrix);
		free(data);
		ft_printf("Process stop successfully\n");
		exit (EXIT_SUCCESS);
	}
	else if (key == 65361)
	{
		mlx_clear_window(data->mlx, data->win);
		data->theta += PI / 12;
		draw(data);
	}
	else if (key == 65363)
	{
		mlx_clear_window(data->mlx, data->win);
		data->theta -= PI / 12;
		draw(data);
	}
	else if (key == 65362)
	{
		mlx_clear_window(data->mlx, data->win);
		data->phi -= PI / 12;
		draw(data);
	}
	else if (key == 65364)
	{
		mlx_clear_window(data->mlx, data->win);
		data->phi += PI / 12;
		draw(data);
	}
	else if (key == 65451)
	{
		mlx_clear_window(data->mlx, data->win);
		data->ecart += 10;
		draw(data);
	}
	else if (key == 65453)
	{
		mlx_clear_window(data->mlx, data->win);
		data->ecart -= 10;
		draw(data);
	}
	else
		ft_printf("%d\n", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = initialize_fdf(argc, argv);
	draw(fdf);
	printf("x_min = %d\tx_max = %d\ny_min = %d\ty_max = %d\n", fdf->x_min, fdf->x_max, fdf->y_min, fdf->y_max);
	printf("ecart = %d\n", fdf->ecart);
	//ft_printf("%d\t%d\n", fdf->x_pos, fdf->y_pos);
	mlx_key_hook(fdf->win, key_handler, fdf);
	mlx_loop(fdf->mlx);
}