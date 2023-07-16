/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:52:19 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:08 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	stack_len(t_node *stack)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = last_first_node(stack, false);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1++ != *s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	}
	return (0);
}

void	check_exit_else_exec(t_node **stack_a, t_node **stack_b, char *line)
{
	if (stack_a == NULL || stack_b == NULL)
		ft_printf("%s\n", line);
	else if (is_sorted(*stack_a, false) && stack_len(*stack_b) == 0)
	{
		clear_lst_node(*stack_a);
		clear_lst_node(*stack_b);
		exit(0);
	}
	else if (line != NULL)
		ft_printf("%s\n", line);
}
