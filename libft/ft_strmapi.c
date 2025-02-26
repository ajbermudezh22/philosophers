/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:06:04 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/07 10:51:16 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*mapped_str;
	size_t			string_length;

	if (s == NULL)
		return (NULL);
	string_length = ft_strlen(s);
	mapped_str = malloc(sizeof(char) * (string_length + 1));
	if (mapped_str == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		mapped_str[index] = f(index, s[index]);
		index++;
	}
	mapped_str[index] = '\0';
	return (mapped_str);
}
/*
char uppercase(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char shift_by_index(unsigned int i, char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        int shift = (c + i) % 26;
        if (c >= 'a' && c <= 'z')
            return (shift < 'a') ? 'z' - ('a' - shift - 1) : shift;
        else
            return (shift < 'A') ? 'Z' - ('A' - shift - 1) : shift;
    }
    return c;
}

int main() {
    char *result;
    char *input = "example string";

    // Test 1: Uppercase conversion
    result = ft_strmapi(input, uppercase);
    printf("Uppercase: %s\n", result);
    free(result); // Don't forget to free memory!

    // Test 2: Character shift by index
    result = ft_strmapi(input, shift_by_index);
    printf("Shifted by Index: %s\n", result);
    free(result);
    return 0;
}
*/