/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:08:05 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:13:28 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
static void print_content(void *content)
{
    printf("%d ", *(int *)content);
}

int main()
{
    t_list *head = NULL;
    int vals[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        t_list *new_node = ft_lstnew(&vals[i]);
        ft_lstadd_back(&head, new_node);
    }

    ft_lstiter(head, print_content);  // Should print: 1 2 3
    printf("\n");
    return 0;
}
*/
