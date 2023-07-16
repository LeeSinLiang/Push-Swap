/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:07:36 by sinlee            #+#    #+#             */
/*   Updated: 2023/07/16 04:11:19 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push_swap program
// pos[0] = pos_a, pos[1] = pos_b
int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		while (++i < argc)
		{
			if (is_valid(stack_a, argv[i]) == false)
				ft_error(stack_a);
			stack_a = add_node(stack_a, ft_atoi(argv[i]));
		}
		push_swap(stack_a, stack_b, argc - 1);
		clear_lst_node(stack_a);
		clear_lst_node(stack_b);
	}
	return (0);
}
