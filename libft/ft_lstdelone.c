/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:03:11 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:33:13 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
/*
static void del(void *content) {
    free(content);
}

int main()
{
    int *val = malloc(sizeof(int));
    *val = 10;
    t_list *node = ft_lstnew(val);

    ft_lstdelone(node, del);
    printf("Node after delete: %p\n", (void *)node);  
	// This will not print NULL as node is a local variable, 
	// use valgrind to check for proper deletion
    return 0;
}
*/
