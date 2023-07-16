/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:28:28 by codespace         #+#    #+#             */
/*   Updated: 2023/07/16 04:11:18 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checker for push_swap program

#include "checker.h"

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*line;
	char	**split;

	line = get_next_line(0);
	while (line)
	{
		split = ft_split(line, '\n');
		if (ft_strchr(line, '\n') == 0 || split[0] == 0)
			ft_error(*stack_a);
		free(line);
		if (execute(stack_a, stack_b, split[0], true) == false)
			ft_error(*stack_a);
		free(split[0]);
		free(split);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a, false) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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
			{
				ft_printf("Triggered\n");
				ft_error(stack_a);
			}
			stack_a = add_node(stack_a, ft_atoi(argv[i]));
		}
		checker(&stack_a, &stack_b);
		clear_lst_node(stack_a);
		clear_lst_node(stack_b);
	}
}
