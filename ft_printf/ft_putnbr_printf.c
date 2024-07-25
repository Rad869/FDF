/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:23:26 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 06:39:33 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(long int n, int fd)
{
	char	c;

	c = 0;
	if (n == -2147483648)
	{
		ft_putstr_printf("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * (-1);
	}
	if (n / 10)
		ft_putnbr_printf(n / 10, fd);
	c = '0' + (n % 10);
	ft_putchar_printf(c, fd);
}

int	ft_putunsignednbr_fd(unsigned long n, int fd)
{
	int		count;
	char	c;

	c = 0;
	count = 0;
	if (n / 10)
		count += ft_putunsignednbr_fd((unsigned long )(n / 10), fd);
	c = '0' + (n % 10);
	return (write(fd, &c, 1) + count);
}
