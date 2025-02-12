/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archytekt <archytekt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:00:14 by lmaria            #+#    #+#             */
/*   Updated: 2025/02/12 00:51:34 by archytekt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	process_conversion(const char *format, va_list args, int count,
		unsigned long ptr)
{
	if (*format == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		count += ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		count += ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	else if (*format == 'X')
		count += ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	else if (*format == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			return (count += ft_putstr_fd("(nil)", 1));
		count += ft_putstr_fd("0x", 1);
		count += ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
	}
	else if (*format == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

static int	process_format_string(const char *format, va_list args, int count)
{
	unsigned long	ptr;

	ptr = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = process_conversion(format, args, count, ptr);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = process_format_string(format, args, count);
	va_end(args);
	return (count);
}
