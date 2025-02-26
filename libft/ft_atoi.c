/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:51:59 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:08:27 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (sign == -1 && - result < INT_MIN)
			return (0);
		else if (sign == 1 && result > INT_MAX)
			return (-1);
		str++;
	}
	return ((int)(sign * result));
}

/*
int main() 
{
    char *strings[] = {"42", "   -42", "0", "+123", "2147483647", "-2147483648", 
	"9999999999", "-9999999999", "invalid123", NULL};
    int i = 0;
    
    while (strings[i]) 
	{
        printf("ft_atoi('%s') = %d\n", strings[i], ft_atoi(strings[i]));
        i++;
    }
    return 0;
}
*/
