/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:56:49 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 11:41:46 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// implementation of isalnum function

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// test ft_isalnum function
// #include <ctype.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	printf("%d\n", ft_isalnum((int)*(argv[1])));
// 	printf("%d\n", isalnum((int)*(argv[1])));
// }
