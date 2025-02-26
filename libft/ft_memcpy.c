/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:01:05 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 13:59:03 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	destination = (char *)dest;
	source = (const char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char s1[5];
	const char *s2 = "hola";

	ft_memcpy(s1, s2, 4);
	s1[4] = '\0';
	printf("%s\n",s1);
}
*/
