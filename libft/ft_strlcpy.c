/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:25:56 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:30:29 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!dst && !src)
		return (0);
	if (size == 0)
		return (src_len);
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (src_len);
}
/*
int main()
{
    char dest[20];
    const char *src = "Hello, World!";
    size_t copied = ft_strlcpy(dest, src, sizeof(dest));
    printf("Copied '%s' with length %zu\n", dest, copied);
    return 0;
}
*/
