/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:58:56 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:34:15 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(const char *str, char delimiter)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != delimiter)
		{
			count++;
			while (*str && *str != delimiter)
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	size_t	token_index;
	size_t	token_len;

	token_index = 0;
	tokens = malloc(sizeof(char *) * (count_tokens(s, c) + 1));
	if (!s || !tokens)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			token_len = 0;
			while (*s && *s != c)
			{
				token_len++;
				s++;
			}
			tokens[token_index++] = ft_substr(s - token_len, 0, token_len);
		}
		else
			s++;
	}
	tokens[token_index] = NULL;
	return (tokens);
}
/*

// Function to print resulting strings from split_string
void print_strings(char **strings) {
    if (strings) {
        int i = 0;
        while (strings[i]) {
            printf("Token %d: %s\n", i + 1, strings[i]);
            i++;
        }
    } else {
        printf("No tokens found.\n");
    }
}

int main(void) {
    char **result;
    char const *input;
    char delimiter;

    // Test 1: Regular input
    input = "hello world here I come";
    delimiter = ' ';
    printf("Test 1: Splitting \"%s\" by '%c'\n", input, delimiter);
    result = ft_split(input, delimiter);
    print_strings(result);
    // Free memory
    int i = 0;
    while (result[i]) {
        free(result[i]);
        i++;
    }
    free(result);

    // Test 2: Delimiter not in string
    input = "hello world";
    delimiter = ',';
    printf("Test 2: Splitting \"%s\" by '%c'\n", input, delimiter);
    result = ft_split(input, delimiter);
    print_strings(result);
    i = 0;
    while (result[i]) {
        free(result[i]);
        i++;
    }
    free(result);

    // Test 3: String starts and ends with delimiter
    input = "!!hello!!world!!";
    delimiter = '!';
    printf("Test 3: Splitting \"%s\" by '%c'\n", input, delimiter);
    result = ft_split(input, delimiter);
    print_strings(result);
    i = 0;
    while (result[i]) {
        free(result[i]);
        i++;
    }
    free(result);

    // Test 4: Empty string
    input = "";
    delimiter = ';';
    printf("Test 4: Splitting \"%s\" by '%c'\n", input, delimiter);
    result = ft_split(input, delimiter);
    print_strings(result);
    free(result); // Only need to free the array itself if no tokens were created

    // Test 5: String with only delimiters
    input = ";;;;";
    delimiter = ';';
    printf("Test 5: Splitting \"%s\" by '%c'\n", input, delimiter);
    result = ft_split(input, delimiter);
    print_strings(result);
    free(result);

    return 0;
}
*/
