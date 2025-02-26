/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:51:52 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:09:20 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst || new == *lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
static void print_list(t_list *lst) {
    while (lst) {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *head = NULL;
    int vals[] = {1, 2, 3};
    t_list *new_node;

    for (int i = 0; i < 3; i++) {
        new_node = ft_lstnew(&vals[i]);
        ft_lstadd_front(&head, new_node);
    }

    print_list(head);  // Should print: 3 -> 2 -> 1 -> NULL
    return 0;
}
*/
