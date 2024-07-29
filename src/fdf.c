/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:00 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:44:45 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_all(t_fdf *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->img);
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
	return (0);
}

int	key_handler(int key, t_fdf *data)
{
	if (key == 65307)
		close_all(data);
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = initialize_fdf(argc, argv);
	draw(fdf);
	mlx_key_hook(fdf->win, key_handler, fdf);
	mlx_hook(fdf->win, 17, 0, close_all, fdf);
	mlx_loop(fdf->mlx);
}