/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:42 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/16 19:07:36 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_format(const char **format, va_list args)
{
	size_t	total_chars;

	total_chars = 0;
	if (**format == 'c')
		total_chars += ft_print_char(va_arg(args, int));
	else if (**format == 's')
		total_chars += ft_print_string(va_arg(args, char *));
	else if (**format == 'p')
		total_chars += ft_print_pointer(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		total_chars += ft_print_decimal(va_arg(args, int));
	else if (**format == 'u')
		total_chars += ft_print_unsigned(va_arg(args, unsigned int));
	else if (**format == 'x')
		total_chars += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		total_chars += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		total_chars += ft_print_percent();
	return (total_chars);
}

int	format_logic(const char *format, va_list args)
{
	size_t	total_chars;

	total_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_chars += check_format(&format, args);
		}
		else
		{
			write(1, format, 1);
			total_chars++;
		}
		format++;
	}
	return (total_chars);
}
