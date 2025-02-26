/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:05:44 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/07 11:03:41 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current, del);
	}
}
/*
static void del(void *content) {
    free(content);
}

int main() {
    t_list *head = NULL;
    for (int i = 0; i < 3; i++) {
        int *val = malloc(sizeof(int));
        *val = i;
        t_list *new_node = ft_lstnew(val);
        ft_lstadd_back(&head, new_node);
    }

    ft_lstclear(&head, del);
    printf("List after clear: %p\n", (void *)head);  
	// Should print: List after clear: NULL
    return 0;
}
*/
