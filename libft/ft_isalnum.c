/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:45:19 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:00:31 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*

int main() 
{
    char test_chars[] = {'a', 'Z', '1', '0', '%', '\n', ' ', '\0', '9'};
    for (int i = 0; i < sizeof(test_chars) / sizeof(char); i++) {
        printf("ft_isalnum('%c') = %d (Expected: %d)\n", test_chars[i], 
		ft_isalnum(test_chars[i]), isalnum(test_chars[i]));
    }
    return 0;
}
*/
