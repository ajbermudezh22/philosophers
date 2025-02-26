/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:41:14 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:29:53 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}
/*
int main()
{
    const char *str = "Hello, World!";
    char *result = ft_strchr(str, 'W');
    if (result)
        printf("Found: %c\n", *result);
    else
        printf("Character not found\n");
    return 0;
}
*/
