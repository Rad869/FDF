/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:21:01 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/27 10:32:49 by rrabeari         ###   ########.fr       */
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

int	get_row(char *fname)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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

int	convert_hexa(char *s)
{
	int	value;
	int	i;
	int	tmp;

	value = 0;
	tmp = 0;
	i = ft_strlen(s) * 4 - 4;
	if (ft_strchr(s, '\n'))
		i -= 4;
	while (i >= 0)
	{
		if (*s <= 'F' && *s >= 'A')
			tmp = *s - 'A' + 10;
		else if (*s <= 'f' && *s >= 'a')
			tmp = *s - 'a' + 10;
		else if (*s >= '0' && *s <= '9')
			tmp = *s - '0';
		else
			p_error("Color error", "You entered an error format of color");
		value += (tmp << i);
		s++;
		i -= 4; 
	}
	return (value);
}

void	fill_color(int *c_line, char *line)
{
	char	**args;
	char	*char_tmp;
	int		i;

	i= 0;
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
	data->c_matrix = (int **)malloc(sizeof(int *) * (data->len_row + 1));
	while (i < data->len_row)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->len_col + 1));
		data->c_matrix[i] = (int *)malloc(sizeof(int) * (data->len_col + 1));
		i++;
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i], line);
		fill_color(data->c_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}