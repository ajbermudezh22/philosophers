/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:57:08 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:44 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    char str3[] = "Hello, World!";  // Note the capital 'W'
    char str4[] = "Hello, ward!";

    // Test identical strings
    printf("T1 (identical): %d\n", ft_memcmp(str1, str2, sizeof(str1)));

    // Test similar strings, case difference
    printf("T2 (case difference): %d\n", ft_memcmp(str1, str3, sizeof(str1)));

    // Test different strings
    printf("T3 (different content): %d\n", ft_memcmp(str1, str4, sizeof(str1)));

    // Test zero length
    printf("T4 (zero length): %d\n", ft_memcmp(str1, str2, 0));

    return 0;
}
*/
