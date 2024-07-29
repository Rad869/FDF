/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:00 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 06:25:14 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
int	get_blue(int color);
int	get_green(int color);
int	get_red(int color);

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = initialize_fdf(argc, argv);
	draw(fdf);
	for(int j = 0; j < fdf->len_row; j++)
	{
		for(int i = 0; i <fdf->len_col; i++)
		{
			ft_printf("%d", fdf->c_matrix[j][i]);
			ft_printf("(red : %d\tgreen : %d\tblue : %d)\t", get_red(fdf->c_matrix[j][i]), get_green(fdf->c_matrix[j][i]), get_blue(fdf->c_matrix[j][i]));
		}
		ft_printf("\n");
	}
	mlx_key_hook(fdf->win, key_handler, fdf);
	mlx_loop(fdf->mlx);
}