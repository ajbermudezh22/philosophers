/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:07:55 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/16 21:07:27 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	tmp;
	int				len;

	tmp = n;
	len = 1;
	if (n == 0)
		len = 1;
	else
	{
		while (tmp >= 10)
		{
			tmp /= 10;
			len++;
		}
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

size_t	ft_print_unsigned(unsigned int u)
{
	char	*str;
	size_t	len;

	str = ft_utoa(u);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

char	*ft_itoa_base(unsigned int value, int base, int uppercase)
{
	char			*str;
	const char		*hex_chars;
	unsigned int	tmp;
	int				len;

	hex_chars = "0123456789abcdef";
	if (uppercase)
		hex_chars = "0123456789ABCDEF";
	tmp = value;
	len = 1;
	while (tmp >= (unsigned int)base)
	{
		tmp /= base;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = hex_chars[value % base];
		value /= base;
	}
	return (str);
}

size_t	ft_print_hex(unsigned int x, int uppercase)
{
	char	*str;
	size_t	len;

	str = ft_itoa_base(x, 16, uppercase);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

size_t	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
