/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:54:14 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/02 16:00:46 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*value;
	size_t			len;
	unsigned int	i;

	len = ft_strlen((char *) s);
	i = 0;
	value = (char *) malloc(sizeof(char) * (len + 1));
	if (value == NULL)
		return (NULL);
	while (s[i])
	{
		value[i] = f(i, s[i]);
		i++;
	}
	value[i] = '\0';
	return (value);
}
