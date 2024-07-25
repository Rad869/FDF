/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:25:32 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/03 12:44:04 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *) s;
	while (i < (int) n)
	{
		if (a[i] == (unsigned char) c)
			return ((void *)&a[i]);
		i++;
	}
	return (NULL);
}
