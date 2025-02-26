/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:02:30 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:11:26 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
char *ft_substr(char const *s, unsigned int start, size_t len);

int main() {
    const char *str = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;

    char *substring = ft_substr(str, start, len);
    if (substring) {
        printf("Substring: '%s'\n", substring);
        free(substring);
    } else {
        printf("Failed to allocate memory for substring.\n");
    }

    return 0;
}
*/
