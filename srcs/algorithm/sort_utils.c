/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:37:28 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:10 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *stack, bool reverse)
{
	t_node	*tmp;

	tmp = last_first_node(stack, false);
	if (stack_len(stack) == 0 || !stack)
		return (false);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content && reverse == false)
			return (false);
		if (tmp->content < tmp->next->content && reverse == true)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

// retrieve the first index found that matches the target
int	node_index(t_node *stack, int target)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = last_first_node(stack, false);
	if (stack_len(stack) == 0 || !stack)
		return (-1);
	while (tmp)
	{
		if (tmp->content == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

// attr[0] = traverse_index, attr[1] = target_index
int	min_max_pos(t_node *stack, bool max, bool pos)
{
	int		target;
	int		attr[2];
	t_node	*tmp;

	tmp = last_first_node(stack, false);
	attr[0] = -1;
	attr[1] = 0;
	target = tmp->content;
	while (++attr[0] < stack_len(stack))
	{
		if ((tmp->content > target && max == true) || (tmp->content < target
				&& max == false))
		{
			target = tmp->content;
			attr[1] = attr[0];
		}
		tmp = tmp->next;
	}
	if (pos == true)
		return (attr[1]);
	else
		return (target);
}

void	min_max_push(t_node *stack, bool max)
{
	int	pos;

	pos = min_max_pos(stack, max, true);
	target_push(stack, pos);
}

int	find_min_index(t_node *stack_a, t_node *stack_b, int len)
{
	int		min;
	int		index[2];
	t_node	*tmp;

	tmp = last_first_node(stack_a, false);
	min = execute_calc(stack_a, stack_b, len, false);
	index[0] = 0;
	index[1] = 0;
	while (tmp)
	{
		if (execute_calc(tmp, stack_b, len, false) < min)
		{
			min = execute_calc(tmp, stack_b, len, false);
			index[1] = index[0];
		}
		tmp = tmp->next;
		index[0]++;
	}
	return (index[1]);
}
