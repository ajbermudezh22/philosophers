/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:26:46 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:16:52 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	end = len;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	while (end > start && char_in_set(s1[end - 1], set))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}

/*
int main(void)
{
    char const *s1;
    char const *set;
    char *result;

    // Test 1: Regular trimming
    s1 = "###Hello, World###";
    set = "#";
    result = ft_strtrim(s1, set);
    printf("Test 1 - Expected: Hello, World | Result: %s\n", result);
    free(result); // Free memory after use

    // Test 2: No trimming needed
    s1 = "Hello, World";
    set = "#";
    result = ft_strtrim(s1, set);
    printf("Test 2 - Expected: Hello, World | Result: %s\n", result);
    free(result);

    // Test 3: Trim all characters
    s1 = "#####";
    set = "#";
    result = ft_strtrim(s1, set);
    printf("Test 3 - Expected: (empty) | 
	Result: %s\n", result ? result : "(null)");
    free(result);

    // Test 4: Empty string input
    s1 = "";
    set = "#";
    result = ft_strtrim(s1, set);
    printf("Test 4 - Expected: (empty) | 
	Result: %s\n", result ? result : "(null)");
    free(result);

    // Test 5: NULL pointers (should be handled if your ft_strtrim handles NULL)
    s1 = NULL;
    set = "#";
    result = ft_strtrim(s1, set);
    printf("Test 5 - Expected: (null) | Result: 
	%s\n", result ? result : "(null)");

    return 0;
}
*/