/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:41:52 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 11:47:03 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// implementation of isascii function

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// test ft_isascii function
// #include <ctype.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	printf("%d\n", ft_isascii((int)*(argv[1])));
// 	printf("%d\n", isascii((int)*(argv[1])));
// }