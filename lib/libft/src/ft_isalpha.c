/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:45:29 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 10:51:45 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// test ft_isalpha function
// #include <ctype.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	printf("%d\n", ft_isalpha((int)*(argv[1])));
// 	printf("%d\n", isalpha((int)*(argv[1])));
// }
