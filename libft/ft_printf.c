/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:15:57 by albbermu          #+#    #+#             */
/*   Updated: 2024/06/02 15:35:37 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	total_chars;
	va_list	args;

	va_start(args, format);
	total_chars = format_logic(format, args);
	va_end(args);
	return (total_chars);
}
/*
#include <stdio.h>

int main(void)
{
    ft_printf("Hello, World!\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "This is a string");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", 123);
    ft_printf("Integer: %i\n", -123);
    ft_printf("Unsigned: %u\n", 123);
    ft_printf("Hex (lowercase): %x\n", -15);
	printf("Hex (lowercase) -printf: %x\n", -15);
    ft_printf("Hex (uppercase): %X\n", 0xABCDEF);
    ft_printf("Percent sign: %%\n");

    return 0;
}
*/
