/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:45:56 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 14:59:22 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
/*

int	main(void)
{
	char	buffer[] = "abcde";
	int i;
	ft_bzero(buffer, 3);
	for (i=0; i <sizeof(buffer); i++)
	{
		printf("buffer[%d] = %d\n", i, buffer[i]);
	}
	
}
*/
