/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 02:07:07 by codespace         #+#    #+#             */
/*   Updated: 2023/07/17 09:43:44 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculate the number of moves needed to push to stack b

#include "push_swap.h"

// least common move
// 'rr' (0) or 'rrr' (1)
// nlcm[2]: nlcm[0] = rr, nlcm[1] = rrr

static int	min_lcm(int *arr, int len, bool return_index)
{
	int	min;
	int	i;
	int	target_index;

	i = 0;
	target_index = 0;
	min = arr[0];
	while (++i < len)
	{
		if (arr[i] < min && arr[i] >= 0)
		{
			min = arr[i];
			target_index = i;
		}
	}
	if (return_index == true)
		return (target_index);
	else
		return (min);
}

// calculate minimum moves only, does not reflect actual how to
// pos[2], pos[0] = pos_a, pos[1] = pos_b
int	lcm(int pos[2], int len_a, int len_b, bool return_move)
{
	int	nlcm[4];
	int	temp_pos_b;

	temp_pos_b = -1;
	if (pos[1] == 0)
	{
		temp_pos_b = pos[1];
		pos[1] = pos[0];
	}
	if (pos[0] < pos[1])
		nlcm[0] = pos[1];
	else
		nlcm[0] = pos[0];
	if (len_a - pos[0] < len_b - pos[1])
		nlcm[1] = (len_b - pos[1]);
	else
		nlcm[1] = (len_a - pos[0]);
	nlcm[2] = pos[0] + (len_b - pos[1]);
	nlcm[3] = (len_a - pos[0]) + pos[1];
	if (temp_pos_b != -1)
		pos[1] = temp_pos_b;
	if (return_move == true)
		return (min_lcm(nlcm, 4, true));
	else
		return (min_lcm(nlcm, 4, false));
}

// stack_a is the current pointer towards the certain element in linked_list.
// not the first!
// target_attr[2]: target_attr[0] = target, target_attr[1] = is_init
// nmoves_to_top[2]: nmoves_to_top[0] = a, nmoves_to_top[1] = b
// + 1 for push to stack
int	calc(t_node *stack_a, t_node *stack_b, int len, bool return_pos_b)
{
	t_node	*tmp;
	int		nmoves_to_top[2];
	int		target;

	nmoves_to_top[0] = node_index(stack_a, stack_a->content);
	tmp = last_first_node(stack_b, false);
	if (stack_b)
	{
		target = tmp->content;
		while (tmp)
		{
			if ((tmp->content > target && tmp->content < stack_a->content)
				|| (tmp->content < stack_a->content
					&& target > stack_a->content))
				target = tmp->content;
			tmp = tmp->next;
		}
		nmoves_to_top[1] = node_index(stack_b, target);
		if (return_pos_b == true)
			return (nmoves_to_top[1]);
		else
			return (lcm(nmoves_to_top, len, stack_len(stack_b), false) + 1);
	}
	return (nmoves_to_top[0] + 1);
}

int	execute_calc(t_node *stack_a, t_node *stack_b, int len, bool return_pos_b)
{
	int	nmoves;
	int	pos[2];

	if ((stack_a->content < min_max_pos(stack_b, false, false))
		|| (stack_a->content > min_max_pos(stack_b, true, false)))
	{
		pos[0] = node_index(stack_a, stack_a->content);
		pos[1] = min_max_pos(stack_b, true, true);
		if (return_pos_b == true)
			nmoves = pos[1];
		else
			nmoves = (lcm(pos, stack_len(stack_a), stack_len(stack_b), false)
					+ 1);
	}
	else
		nmoves = calc(stack_a, stack_b, len, return_pos_b);
	return (nmoves);
}
