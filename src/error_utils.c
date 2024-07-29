/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:55:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 20:31:16 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
*	Print the error and stop the program
*	title : Title of the error
*		Ex: Error : number of args too small
			Please make the args just one
*/
void	p_error(char *title, char *err)
{
	ft_printf(BRED"ERROR :"RED" %s\n"CRESET, title);
	ft_printf("%s\n\n"CRESET, err);
	exit(EXIT_FAILURE);
}

void	check_char_entry(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]) || line[i] == '\t' || line[i] == '\n' || \
				ft_strchr("0 -,xabcdefABCDEF", (int) line[i]))
				i++;
			else
			{
				close(fd);
				free(line);
				p_error("Content maps error", "You enterend an other input");
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	check_empty(char *fname)
{
	int	col;

	col = get_col(fname);
	printf("%d\n", col);
	if (col == 0)
		p_error("Maps Error", "Empty file entered");
}
