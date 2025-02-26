/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:09:28 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/07 11:04:56 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	new_list = NULL;
	while (lst != NULL)
	{
		new_element = ft_lstnew(f(lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
/*
static void del(void *content) {
    free(content);
}

static void *increment(void *content) {
    int *new_val = malloc(sizeof(int));
    *new_val = *(int *)content + 1;
    return new_val;
}

static void print_content(void *content) {
    printf("%d ", *(int *)content);
}

int main() {
    t_list *head = NULL;
    int vals[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        int *new_int = malloc(sizeof(int));
        *new_int = vals[i];
        t_list *new_node = ft_lstnew(new_int);
        ft_lstadd_back(&head, new_node);
    }

    t_list *mapped_head = ft_lstmap(head, increment, del);
    ft_lstiter(mapped_head, print_content);  // Should print: 2 3 4
    printf("\n");

    ft_lstclear(&head, del);
    ft_lstclear(&mapped_head, del);
    return 0;
}
*/
