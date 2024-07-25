/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:21:01 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/24 07:21:34 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_col(char *fname)
{
	int		wrd;
	int		fd;
	char	*line;

	wrd = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	wrd = ft_wrdcount(line);
	free(line);
	close(fd);
	return (wrd);
}

int get_row(char *fname)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)))
	{
		row++;
		free(line);
	}
	close(fd);
	return (row);
}

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

void	read_entry(char	*fname, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(fname, O_RDONLY);
	data->len_col = get_col(fname);
	data->len_row = get_row(fname);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->len_row + 1));
	while (i <= data->len_row)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->len_col + 1));
		i++;
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	close(fd);
}