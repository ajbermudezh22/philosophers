/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:48:20 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:01:33 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_occurrence = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		last_occurrence = (char *)str;
	return (last_occurrence);
}
/*
int main()
{
    const char *str = "Hello, World! Hello again!";
    char *result = ft_strrchr(str, 'H');
    if (result)
        printf("Last occurrence: %s\n", result);
    else
        printf("Character not found\n");
    return 0;
}
*/
