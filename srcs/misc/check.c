/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:33:27 by codespace         #+#    #+#             */
/*   Updated: 2023/07/17 14:31:39 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_node *stack_a)
{
	clear_lst_node(stack_a);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static bool	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	ft_atoi_ps(char *str, t_node *stack_a)
{
	long long int	ans;
	int				result;

	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error(stack_a);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(stack_a);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
		ft_error(stack_a);
	return (result * ans);
}

bool	is_valid(t_node *stack_a, char *str)
{
	t_node	*tmp;
	int		nbr;

	tmp = last_first_node(stack_a, false);
	nbr = ft_atoi_ps(str, stack_a);
	while (tmp)
	{
		if (tmp->content == nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2])
{
	pos[0] = stack_len(*stack_a) - pos[0];
	if (pos[1] != 0)
		pos[1] = stack_len(*stack_b) - pos[1];
}
