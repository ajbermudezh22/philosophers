/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:50:53 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/03 14:06:44 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*mem;
	size_t	total_size;
	size_t	i;

	if (size && (nitems > SIZE_MAX / size))
		return (NULL);
	total_size = nitems * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
/*
int main() 
{
    int *data = (int *)ft_calloc(4, sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; i < 4; i++) {
        printf("%d ", data[i]);  // Should print: 0 0 0 0
    }
    free(data);
    return 0;
}
*/