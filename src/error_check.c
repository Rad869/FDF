/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:33:09 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 20:29:27 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	check_entry(int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
		p_error("Number of arguments", "Argument less or More than expected");
	else if ((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4)) != 0)
		p_error("Argument extension", BLU"Tips :./fdf <filename>.fdf");
}

static void	check_r_c_maps(int fd)
{
	char	**args;
	char	*line;
	int		col;
	int		tmp;

	tmp = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		args = ft_split(line, ' ');
		col = d_tab_len(args);
		if (tmp == 0)
			tmp = col;
		tab_free(args);
		free(line);
		if (col != tmp)
		{
			close(fd);
			p_error("Maps", "Map doesn't have the same num of col");
		}
		line = get_next_line(fd);
	}
}

void	check_maps(int argc, char *argv[])
{
	int	fd;

	check_entry(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		p_error("Opening the file", "Can't open the file given in argument");
	check_empty(argv[1]);
	check_char_entry(fd);
	check_r_c_maps(fd);
	close(fd);
}
