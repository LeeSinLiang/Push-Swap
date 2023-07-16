/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:59:58 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:09 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// identify the position of the target in stack_a
int	find_target(t_node *stack_from, t_node *stack_to)
{
	t_node	*tmp;
	int		target;

	tmp = last_first_node(stack_to, false);
	target = tmp->content;
	if (stack_from->content > min_max_pos(stack_to, true, false))
		return (min_max_pos(stack_to, false, true));
	while (tmp)
	{
		if ((tmp->content < target && tmp->content > stack_from->content)
			|| (tmp->content > stack_from->content
				&& target < stack_from->content))
			target = tmp->content;
		tmp = tmp->next;
	}
	return (node_index(stack_to, target));
}

void	target_push(t_node *stack, int pos)
{
	int	len;

	stack = last_first_node(stack, false);
	len = stack_len(stack);
	if (pos <= len / 2)
	{
		while (pos--)
			execute(&stack, NULL, "ra", false);
	}
	else
	{
		pos = len - pos;
		while (pos--)
			execute(&stack, NULL, "rra", false);
	}
}

void	exec_smt(t_node **stack_a, t_node **stack_b, int pos[2], int mode)
{
	if (mode == 0)
	{
		multi_execute(stack_a, stack_b, "rr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_a, "ra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1])
			multi_execute(stack_a, stack_b, "rb", pos[1] - pos[0]);
	}
	else if (mode == 1)
	{
		multi_execute(stack_a, stack_b, "rrr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_a, "rra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1]
			&& pos[1] != 0)
			multi_execute(stack_a, stack_b, "rrb", pos[1] - pos[0]);
	}
}
