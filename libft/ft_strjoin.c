/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:19:13 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/02 11:28:21 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*value;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	value = (char *) malloc(sizeof(*s1) * (len1 + len2 + 1));
	if (value == 0)
		return (NULL);
	while (i < (len1 + len2))
	{
		if (i < len1)
			value[i] = s1[i];
		else
			value[i] = s2[i - len1];
		i++;
	}
	value[i] = 0;
	return (value);
}
