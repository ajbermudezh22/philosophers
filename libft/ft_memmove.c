/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:16:00 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:51 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (!dest && !src)
		return (0);
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*pd++ = *ps++;
	}
	else
	{
		ps += n - 1;
		pd += n - 1;
		while (n--)
			*pd-- = *ps--;
	}
	return (dest);
}
/*
int main(void)
{
	char test1_src[] = "Hello world!";
	char test1_dest[50];

	ft_memmove(test1_dest, test1_src, strlen(test1_src) + 1);
	printf("Non-overlapping: %s\n",test1_dest);

	    // Test 2: Overlapping, dest is after src
    ft_memmove(test1_src + 5, test1_src, 7); // "Hello, Hello, world!"
    printf("Overlap, dest after src: %s\n", test1_src);

    // Test 3: Overlapping, src is after dest
    ft_memmove(test1_src, test1_src + 7, 6); // "world!world!"
    printf("Overlap, src after dest: %s\n", test1_src);

    // Test 4: Zero-length operation
    ft_memmove(test1_dest, test1_src, 0);
    printf("Zero-length operation: %s\n", test1_dest); // Should be unchanged

    // Test 5: Identical src and dest
    ft_memmove(test1_src, test1_src, strlen(test1_src) + 1);
    printf("Identical src and dest: %s\n", test1_src);

    return 0;
}
*/
