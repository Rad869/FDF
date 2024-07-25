/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:25 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 05:41:32 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_int(va_list *list)
{
	int	i;
	int	count;

	count = 0;
	i = va_arg(*list, int);
	if (!i)
		return (write(1, "0", 1));
	if (i < 0)
		count++;
	ft_putnbr_printf(i, 1);
	while (i)
	{
		i /= 10;
		count++;
	}
	return (count);
}

int	write_char(va_list *list)
{
	char	c;

	c = (char)va_arg(*list, int);
	ft_putchar_printf(c, 1);
	return (1);
}

int	write_str(va_list *list)
{
	int		count;
	char	*str;

	str = va_arg(*list, char *);
	if (!str)
		return (write(1, "(null)", 6));
	count = ft_strlen_printf(str);
	ft_putstr_printf(str, 1);
	return (count);
}

int	write_ptr(va_list *list)
{
	int					count;
	unsigned long long	ptr;

	ptr = 0;
	count = 0;
	ptr = (unsigned long long) va_arg(*list, unsigned long long);
	if (!ptr)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_puthexa(ptr, 'a');
	}
	return (count);
}

int	write_u(va_list *list)
{
	int				count;
	unsigned long	param;

	count = 0;
	param = (unsigned long) va_arg(*list, long long);
	if (param == 0)
		return (write(1, "0", 1));
	param = param % 4294967296;
	if (param >= 4294967295)
		return (write(1, "4294967295", 10));
	count += ft_putunsignednbr_fd(param, 1);
	return (count);
}
