/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:04 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:05:56 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(str1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
/*
// Assuming the declaration of ft_strdup is in "libft.h"
char *ft_strdup(const char *str1);

int main() {
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);  // Don't forget to free the allocated memory
    } else {
        printf("Failed to allocate memory for duplicate string.\n");
    }

    return 0;
}
*/
