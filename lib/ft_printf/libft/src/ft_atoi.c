/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:33:07 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 09:38:36 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

static bool	is_space(char c)
{
	return (is_in_string(c, "\t\n\v\f\r "));
}

int	ft_atoi(const char *str)
{
	int	ans;
	int	result;

	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans *= 10;
		ans += *str - 48;
		str++;
	}
	return (result * ans);
}
