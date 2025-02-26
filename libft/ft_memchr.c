/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:37:45 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:33 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*s == ch)
			return (s);
		s++;
		n--;
	}
	return (NULL);
}
/*
int main(void)
{
	char *s1 = "hola";
	char d = 'o';
	char *found = (char *)ft_memchr(s1, d, 4);
	    if (found != NULL)
        printf("%s\n", found); 
    else
        printf("Character not found\n");

    return 0;
}
*/
