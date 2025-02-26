/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:46:56 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:00:37 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*

int main() 
{
    int test[] = {0, 127, 128, -1, 65};  // ASCII values and some edge cases
    for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
        printf("ft_isascii(%d) = %d (Expected: %d)\n", test[i], 
		ft_isascii(test[i]), isascii(test[i]));
    }
    return 0;
}
*/