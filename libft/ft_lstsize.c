/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:54:48 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/07 11:05:32 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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

    int size = ft_lstsize(head);
    printf("Size of the list: %d\n", size); 
	// Should print: Size of the list: 3
    return 0;
}
*/
