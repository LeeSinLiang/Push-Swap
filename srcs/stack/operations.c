/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:27:49 by sinlee            #+#    #+#             */
/*   Updated: 2023/07/17 11:18:47 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// double pointer array to get mem address of node
bool	swap(t_node **stack)
{
	t_node	*tmp;

	*stack = last_first_node(*stack, false);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (true);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
	return (true);
}

bool	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return (true);
	*stack_from = last_first_node(*stack_from, false);
	*stack_to = last_first_node(*stack_to, false);
	tmp = (*stack_from)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*stack_from)->next = *stack_to;
	if (*stack_to != NULL)
		(*stack_to)->prev = *stack_from;
	*stack_to = *stack_from;
	*stack_from = tmp;
	return (true);
}

bool	rotate(t_node **stack, bool reverse)
{
	t_node	*tmp;

	*stack = last_first_node(*stack, false);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (true);
	tmp = *stack;
	if (!reverse)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = last_first_node(*stack, true);
		last_first_node(*stack, true)->next = tmp;
	}
	else
	{
		*stack = last_first_node(*stack, true);
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
	return (true);
}

bool	execute(t_node **stack_a, t_node **stack_b, char *line, bool s_print)
{
	if (!s_print)
		ft_printf("%s\n", line);
	if (ft_strcmp(line, "sa") == 0)
		return (swap(stack_a));
	else if (ft_strcmp(line, "sb") == 0)
		return (swap(stack_b));
	else if (ft_strcmp(line, "ss") == 0)
		return (swap(stack_a) && swap(stack_b));
	else if (ft_strcmp(line, "pa") == 0)
		return (push(stack_b, stack_a));
	else if (ft_strcmp(line, "pb") == 0)
		return (push(stack_a, stack_b));
	else if (ft_strcmp(line, "ra") == 0)
		return (rotate(stack_a, false));
	else if (ft_strcmp(line, "rb") == 0)
		return (rotate(stack_b, false));
	else if (ft_strcmp(line, "rr") == 0)
		return (rotate(stack_a, false) && rotate(stack_b, false));
	else if (ft_strcmp(line, "rra") == 0)
		return (rotate(stack_a, true));
	else if (ft_strcmp(line, "rrb") == 0)
		return (rotate(stack_b, true));
	else if (ft_strcmp(line, "rrr") == 0)
		return (rotate(stack_a, true) && rotate(stack_b, true));
	return (false);
}

bool	multi_execute(t_node **stack_a, t_node **stack_b, char *line, int n)
{
	while (n--)
	{
		if (!execute(stack_a, stack_b, line, false))
			return (false);
	}
	return (true);
}
