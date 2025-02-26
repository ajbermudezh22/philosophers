/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:15:32 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:03:34 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	len_little;
	size_t	len_big;

	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (len_little == 0)
		return ((char *)big);
	if (len_big == 0 || n < len_little)
		return (NULL);
	if (n < len_little)
		return (NULL);
	i = 0;
	while (i <= n - len_little && big[i] != '\0')
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
int main()
{
    const char *big = "Hello, World!";
    const char *little = "World";
    char *result = ft_strnstr(big, little, 15);
    if (result)
        printf("Found substring: %s\n", result);
    else
        printf("Substring not found\n");
    return 0;
}
*/
