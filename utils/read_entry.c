/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:21:01 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:21:08 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_matrix(int *z_line, char *line)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split(line, ' ');
	while (args[i])
	{
		z_line[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	free(args);
}

void	fill_color(int *c_line, char *line)
{
	char	**args;
	char	*char_tmp;
	int		i;

	i = 0;
	args = ft_split(line, ' ');
	while (args[i])
	{
		char_tmp = ft_strchr(args[i], ',');
		if (char_tmp == NULL)
			c_line[i] = 0xffffff;
		else
			c_line[i] = convert_hexa(char_tmp + 3);
		i++;
	}
	tab_free(args);
}

static void	fill_all(int fd, t_fdf *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i], line);
		fill_color(data->c_matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	read_entry(char	*fname, t_fdf *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(fname, O_RDONLY);
	data->len_col = get_col(fname);
	data->len_row = get_row(fname);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->len_row + 1));
	data->c_matrix = (int **)malloc(sizeof(int *) * (data->len_row + 1));
	while (i < data->len_row)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->len_col + 1));
		data->c_matrix[i++] = (int *)malloc(sizeof(int) * (data->len_col + 1));
	}
	fill_all(fd, data);
	close(fd);
}
