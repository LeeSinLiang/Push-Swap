/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:13:02 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 17:09:24 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implements lstlast function: return last node of list

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}
// #include <stdio.h>
// int main()
// {
// 	t_list * l =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	printf("%d", *(int *)(ft_lstlast(l)->content));
// }