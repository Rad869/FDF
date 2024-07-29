/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:55:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 12:16:57 by rrabeari         ###   ########.fr       */
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
			if (ft_isdigit((int) line[i]))
				i++;
			else if (ft_strchr("0 ,xabcdefABCDEF", (int) line[i]))
				i++;
			else if (line[i] == '\n' || line[i] == '\t')
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
