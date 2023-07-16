/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:27:55 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 16:31:32 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implements ft_lstmap function:
// iterates the list 'lst' and applies the function 'f' to the 
// content of each node

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new;
	t_list	*temp;

	current = lst;
	new = NULL;
	while (current != NULL)
	{
		temp = ft_lstnew(f(current->content));
		if (temp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		current = current->next;
	}
	return (new);
}
