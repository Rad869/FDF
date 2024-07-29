/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:28:01 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:46:20 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdcount(char *line)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
		if (line[i])
		{
			wc++;
			while (line[i] != ' ' && line[i] != '\t' && line[i])
				i++;
		}
	}
	return (wc);
}
