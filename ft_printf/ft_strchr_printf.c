/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:22:23 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 06:36:22 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_printf(const char *s, int i)
{
	unsigned int	k;
	char			c;

	c = (char) i;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
			return ((char *)&s[k]);
		k++;
	}
	if (c == '\0')
		return ((char *)&s[k]);
	return (NULL);
}
