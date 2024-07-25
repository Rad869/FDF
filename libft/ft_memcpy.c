/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:36:26 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/03 14:31:54 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*t;
	char	*c;

	i = 0;
	c = (char *) src;
	t = (char *) dest;
	if (n != 0 && c != t)
	{
		while (i < n)
		{
			t[i] = c[i];
			i++;
		}
	}
	return (dest);
}
