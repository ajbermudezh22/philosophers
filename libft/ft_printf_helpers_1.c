/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:55 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/16 19:10:22 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_print_string(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

size_t	write_ptr_base_count(void *ptr, char *base, int first_loop_flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				count;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	count = 0;
	if (ptr == NULL)
	{
		count += ft_print_string("(nil)");
		return (count);
	}
	if (first_loop_flag == 1)
		count += ft_print_string("0x");
	if (nbr >= base_length)
		count += write_ptr_base_count((void *)(nbr / base_length), base, 0);
	count += ft_print_char(base[nbr % base_length]);
	return (count);
}

size_t	ft_print_pointer(void *p)
{
	return (write_ptr_base_count(p, "0123456789abcdef", 1));
}

size_t	ft_print_decimal(int d)
{
	char	*str;
	size_t	len;

	str = ft_itoa(d);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
