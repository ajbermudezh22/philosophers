/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:00:35 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:34:49 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
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
    char str1[] = "Hello World";
    char str2[] = "Hello World";
    char str3[] = "Hello there!";
    char str4[] = "Hello Worlf";

    // Test for equal strings
    printf("Test Equal: %d\n", ft_strncmp(str1, str2, 5));  

    // Test for equal strings up to n characters
    printf("Test Up To n Characters: %d\n", ft_strncmp(str1, str2, 11));

    // Test for non-equal strings
    printf("Test Non-Equal: %d\n", ft_strncmp(str1, str3, 11)); 

    // Test where only the last character differs
    printf("Test Last Char Differs: %d\n", ft_strncmp(str1, str4, 11));  

    // Test where strings differ before n
    printf("Test Early Difference: %d\n", ft_strncmp(str1, str3, 7));  

    // Test with n as 0
    printf("Test n is Zero: %d\n", ft_strncmp(str1, str2, 0));  

    // Test including null terminator
    char str5[] = "Hello";
    char str6[] = "Hello\0World";
    printf("Test with Null Terminator: %d\n", ft_strncmp(str5, str6, 10));  

    return 0;
}
*/
