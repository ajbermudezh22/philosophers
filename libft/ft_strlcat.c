/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:33:10 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:34:37 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && (dest_len + i) < (size -1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
int main() {
    char buffer[20] = "Hello";
    char src[] = ", World!";
    size_t result;

    // Test normal concatenation
    result = ft_strlcat(buffer, src, sizeof(buffer));
    printf("Result: %s (length: %zu)\n", buffer, result);

    // Test edge case where buffer is exactly filled
    char buffer2[12] = "Hello";
    result = ft_strlcat(buffer2, src, sizeof(buffer2));
    printf("Result: %s (length: %zu)\n", buffer2, result);

    // Test with buffer almost too small
    char buffer3[10] = "Hello";
    result = ft_strlcat(buffer3, src, sizeof(buffer3));
    printf("Result: %s (length: %zu)\n", buffer3, result);

    // Test with no space left in the buffer
    char buffer4[6] = "Hello";
    result = ft_strlcat(buffer4, src, sizeof(buffer4));
    printf("Result: %s (length: %zu)\n", buffer4, result);

    // Test zero size
    char buffer5[6] = "Hello";
    result = ft_strlcat(buffer5, src, 0);
    printf("Result: %s (length: %zu)\n", buffer5, result);

    return 0;
}
*/
