/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:27:24 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 12:54:04 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of memmove function

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (ptr_dest > ptr_src)
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}

// test ft_memmove function

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[50] = "Hello";
// 	char str2[50] = "WorldHi";
// 	ft_memmove(str1, str2, 3 * sizeof(char));
// 	printf("After memmove():  %s|\n", str1);
// 	char str3[50] = "Hello";
// 	char str4[50] = "WorldHi";
// 	memmove(str3, str4, 3 * sizeof(char));
// 	printf("After memmove():  %s|", str3);
// 	return (0);
// }