/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:53:02 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 06:38:54 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_conv(const char *format, va_list *list, int *count)
{
	if (*format == 'd' || *format == 'i')
		*count += write_int(list);
	else if (*format == 'c')
		*count += write_char(list);
	else if (*format == 'x')
		*count += write_hexamin(list);
	else if (*format == 's')
		*count += write_str(list);
	else if (*format == 'X')
		*count += write_hexamax(list);
	else if (*format == 'p')
		*count += write_ptr(list);
	else if (*format == 'u')
		*count += write_u(list);
	else if (*format == '%')
	{
		*count += 1;
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		ft_putchar_printf(*format, 1);
		*count = *count + 2;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, format);
	if (!ft_strchr_printf(format, '%'))
		return (ft_putstr_printf((char *) format, 1),
			(int) ft_strlen_printf(format));
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			check_conv(format++, &list, &count);
			continue ;
		}
		else
			ft_putchar_printf(*format, 1);
		format++;
		count += 1;
	}
	return (count);
}
