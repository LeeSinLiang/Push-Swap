/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:32:57 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 13:45:45 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implement strnstr function

#include "libft.h"
#include <stdio.h>

static bool	check_occur(char *str, char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	while (to_find[i] != '\0' && len--)
	{
		if (str[i] != to_find[i])
			return (false);
		i++;
	}
	if (to_find[i] != '\0')
		return (false);
	return (true);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_cpy;

	haystack_cpy = (char *)haystack;
	if (!needle[0])
		return (haystack_cpy);
	while (*haystack_cpy && len > 0)
	{
		if (!check_occur(haystack_cpy, (char *)needle, len))
		{
			haystack_cpy++;
			len--;
		}
		else
			return (haystack_cpy);
	}
	return (0);
}

// test ft_strnstr by comparing with strnstr function

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		n;

// 	str1 = argv[1];
// 	str2 = argv[2];
// 	n = atoi(argv[3]);
// 	printf("%s\n", ft_strnstr(str1, str2, n));
// 	printf("%s\n", strnstr(str1, str2, n));
// 	// char haystack[30] = "aaabcabcd";
// 	// printf("%s\n", ft_strnstr(haystack, "abcd", 9));
// 	// printf("%s\n", strnstr(haystack, "abcd", 9));
// 	return (0);
// }
