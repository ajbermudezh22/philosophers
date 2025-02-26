/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:31:12 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:16 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n, int base)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		++counter;
	while (n && ++counter)
		n /= base;
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			len;
	const char	*digits;

	digits = "0123456789";
	len = num_len(n, 10);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		num[0] = '-';
	while (n)
	{
		if (n > 0)
			num[--len] = digits[n % 10];
		else
			num[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (num);
}
/*
int	main(void)
{
	int n1 = 0;
	int n2 = -2147483648;
	int n3 = 2147483647;
	//int n4 = 2147483648;

	char *num1 = ft_itoa(n1);
	char *num2 = ft_itoa(n2);
	char *num3 = ft_itoa(n3);
	//char *num4 = ft_itoa(n4);

	printf("Test 1: %s\n", num1);
	printf("Test 2: %s\n", num2);
	printf("Test 3: %s\n", num3);
	//printf("Test 4: %s\n", num4);
}
*/
