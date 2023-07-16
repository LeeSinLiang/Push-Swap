/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:29:26 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:06 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, char *str, bool advanced, bool to_first)
{
	t_node	*tmp;

	if (to_first == true)
		tmp = last_first_node(stack, false);
	else
		tmp = stack;
	ft_printf("----Printing Stack %s (Top to Down)-------\n", str);
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		if (advanced)
		{
			if (tmp->prev)
				ft_printf("Previous: %d ", tmp->prev->content);
			else
				ft_printf("Previous: NULL ");
			if (tmp->next)
				ft_printf("Next: %d\n", tmp->next->content);
			else
				ft_printf("Next: NULL\n");
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	clear_lst_node(t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	node = last_first_node(node, false);
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

t_node	*add_node(t_node *node, int content)
{
	t_node	*new;

	new = create_node(content);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	new->prev = node;
	return (new);
}

// function that returns either last or first node,
//	depending on the 'is_last' variable. if is_last == true, is last node
t_node	*last_first_node(t_node *node, bool is_last)
{
	if (!node)
		return (NULL);
	if (!is_last)
	{
		while (node->prev)
			node = node->prev;
		return (node);
	}
	else
	{
		while (node->next)
			node = node->next;
		return (node);
	}
}
