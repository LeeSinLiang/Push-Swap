/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:44:43 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:12 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// push swap
// approach no. 1: sort via permutations and divide and conquer
// approach no. 2 (tba): search for the best optimal step to sort before
// actual sorting

#include "push_swap.h"

void	execute_ps(t_node **stack_a, t_node **stack_b, int pos[2], int mode)
{
	if (mode == 0 || mode == 1)
		exec_smt(stack_a, stack_b, pos, mode);
	else if (mode == 2)
	{
		multi_execute(stack_a, stack_b, "ra", pos[0]);
		multi_execute(stack_a, stack_b, "rrb", stack_len(*stack_b) - pos[1]);
	}
	else if (mode == 3)
	{
		multi_execute(stack_a, stack_b, "rra", stack_len(*stack_a) - pos[0]);
		multi_execute(stack_a, stack_b, "rb", pos[1]);
	}
}

void	sort_three(t_node *stack_a)
{
	if (stack_a->content > stack_a->next->content)
	{
		if (stack_a->content < stack_a->next->next->content)
			execute(&stack_a, NULL, "sa", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "rra", false);
		}
		else
			execute(&stack_a, NULL, "ra", false);
	}
	else if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->content > stack_a->next->next->content)
			execute(&stack_a, NULL, "rra", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "ra", false);
		}
	}
}

// push 2 smallest number to stack b, sort 3 stack a, push back to stack a
void	sort_tri_adv(t_node *stack_a, t_node *stack_b, int len)
{
	int	tmp;

	tmp = len;
	while (tmp-- > 3)
	{
		min_max_push(stack_a, false);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort_three(stack_a);
	multi_execute(&stack_a, &stack_b, "pa", len - 3);
}

// attr[3]: attr[0] = min, attr[1] = index, attr[2] = len
void	sort(t_node *stack_a, t_node *stack_b)
{
	int	i;
	int	pos[2];
	int	mode;

	multi_execute(&stack_a, &stack_b, "pb", 2);
	while (stack_len(stack_a) > 3)
	{
		pos[0] = find_min_index(stack_a, stack_b, stack_len(stack_a));
		i = -1;
		while (++i < pos[0])
			stack_a = stack_a->next;
		pos[1] = execute_calc(stack_a, stack_b, stack_len(stack_a), true);
		mode = lcm(pos, stack_len(stack_a), stack_len(stack_b), true);
		if (mode == 1)
			reverse_pos(&stack_a, &stack_b, pos);
		execute_ps(&stack_a, &stack_b, pos, mode);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort_three(stack_a);
	while (stack_len(stack_b) > 0)
	{
		target_push(stack_a, find_target(stack_b, stack_a));
		execute(&stack_a, &stack_b, "pa", false);
	}
	min_max_push(stack_a, false);
}

void	push_swap(t_node *stack_a, t_node *stack_b, int len)
{
	stack_a = last_first_node(stack_a, false);
	if (is_sorted(stack_a, false))
		return ;
	if (len == 2)
		execute(&stack_a, &stack_b, "sa", false);
	else if (len == 3)
		sort_three(stack_a);
	else if (len > 3 && len < 6)
		sort_tri_adv(stack_a, stack_b, len);
	else
		sort(stack_a, stack_b);
}
