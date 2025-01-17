/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:44:40 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/02 15:31:51 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_nbr_int(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	n /= 10;
	while (n)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static void	print_int(char	*s, long n)
{
	if (n / 10)
		print_int(s - 1, n / 10);
	*s = '0' + (n % 10);
}

char	*ft_itoa(int n)
{
	char	*value;
	int		len;
	long	nb;

	nb = (long)n;
	len = check_nbr_int(nb);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (value == NULL)
		return (NULL);
	if (nb < 0)
	{
		value[0] = '-';
		nb *= -1;
	}
	print_int(value + len - 1, nb);
	value[len] = 0;
	return (value);
}
