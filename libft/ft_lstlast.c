/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:57:39 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:33:01 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
    t_list *head = NULL;
    int vals[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        t_list *new_node = ft_lstnew(&vals[i]);
        ft_lstadd_back(&head, new_node);
    }

    t_list *last = ft_lstlast(head);
    printf("Last element: %d\n", *(int *)last->content);  
	// Should print: Last element: 3
    return 0;
}
*/
