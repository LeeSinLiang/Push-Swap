/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:59 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 15:34:40 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of lstnew function: add new node to linked list

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// test ft_lstnew function

// #include <stdio.h>
// int main()
// {
// 	t_list *node;

// 	node = ft_lstnew("hello");
// 	printf("%s", node->content);
// 	return (0);
// }