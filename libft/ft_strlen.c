/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:11:55 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:30:52 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str++)
		++n;
	return (n);
}
/*
int main()
{
    const char *str = "Hello, World!";
    size_t length = ft_strlen(str);
    printf("Length of '%s' is %zu\n", str, length);
    return 0;
}
*/
