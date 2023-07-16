/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:36:51 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 12:57:41 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of memcmp function

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

// test ft_memcmp function by comparing with memcmp function

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char **argv)
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	printf("ft_memcmp: %d\n", ft_memcmp(s2, s3, 4));
// 	printf("memcmp: %d\n", memcmp(s2, s3, 4));
// 	return (0);
// }