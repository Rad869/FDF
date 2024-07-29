/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:28:19 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:14:48 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	module(float var)
{
	if (var < 0)
		return (-var);
	return (var);
}

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
