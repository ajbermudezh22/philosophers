/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:53:26 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/07 10:52:41 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	pos;

	if (s == NULL)
		return ;
	pos = 0;
	while (s[pos] != '\0')
	{
		f(pos, s + pos);
		pos++;
	}
}
/*
// Function to apply to each character, capitalizing it
void capitalize(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = toupper((unsigned char)*c);
    }
}

int main() {
    char str[] = "hello world!";  // Example string

    // Print the original string
    printf("Original: %s\n", str);

    // Apply ft_striteri to the string using the capitalize function
    ft_striteri(str, capitalize);

    // Print the modified string
    printf("Capitalized: %s\n", str);  // Expected output: "HELLO WORLD!"

    return 0;
}
*/
