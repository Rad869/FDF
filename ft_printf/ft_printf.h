/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:45:29 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/23 05:41:32 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_char(char c);
void	print_string(char *s);
char	*ft_strchr_printf(const char *s, int i);
void	ft_putchar_printf(char c, int fd);
void	ft_putnbr_printf(long int n, int fd);
void	ft_putstr_printf(char *s, int fd);
size_t	ft_strlen_printf(const char *s);
int		write_int(va_list *list);
int		write_char(va_list *list);
int		write_ptr(va_list *list);
int		ft_puthexa(unsigned long long param, char c);
int		write_hexamin(va_list *list);
int		write_hexamax(va_list *list);
int		write_str(va_list *list);
int		write_u(va_list *list);
int		ft_putunsignednbr_fd(unsigned long n, int d);

#endif
