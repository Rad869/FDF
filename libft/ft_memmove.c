/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:53:24 by rrabeari          #+#    #+#             */
/*   Updated: 2024/02/24 15:45:24 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*t;
	char	*c;
	size_t	i;

	c = (char *) src;
	t = (char *) dest;
	i = n;
	if (c < t)
		while (i--)
			t[i] = c[i];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
