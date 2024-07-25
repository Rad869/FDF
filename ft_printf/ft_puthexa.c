/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:06:18 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 06:39:38 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long int param, char c)
{
	int	count;

	count = 0;
	if (param / 16)
		count += ft_puthexa(param / 16, c);
	param = param % 16;
	if (param < 10)
		ft_putnbr_printf((int) param, 1);
	else
		ft_putchar_printf(c + (param % 10), 1);
	return (count + 1);
}

int	write_hexamin(va_list *list)
{
	unsigned int	param;
	int				count;
	unsigned int	subst;

	param = 0;
	count = 0;
	param = va_arg(*list, unsigned int);
	if (!param)
		return (write(1, "0", 1));
	subst = param;
	while (subst)
	{
		count += 1;
		subst /= 16;
	}
	ft_puthexa((unsigned long long int) param, 'a');
	return (count);
}

int	write_hexamax(va_list *list)
{
	unsigned int	param;
	unsigned int	subst;
	int				count;

	param = 0;
	count = 0;
	param = va_arg(*list, unsigned int);
	if (!param)
		return (write(1, "0", 1));
	ft_puthexa((unsigned long long int) param, 'A');
	subst = param;
	while (subst)
	{
		count += 1;
		subst /= 16;
	}
	return (count);
}
