/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:02:37 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/28 15:29:27 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implement strchr function

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

// test ft_strchr function

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*ptr;

// 	str = "Hello World";
// 	ptr = ft_strchr(str, 0);
// 	printf("%s\n", ptr);
// 	str = "Hello World";
// 	ptr = strchr(str, 0);
// 	printf("%s\n", ptr);
// 	return (0);
// }
