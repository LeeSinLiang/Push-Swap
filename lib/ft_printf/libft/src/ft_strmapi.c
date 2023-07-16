/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:04 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 15:27:34 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implement strmapi function: apply function to each character of string

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// test ft_strmapi function
// #include <stdio.h>

// char	ft_test(unsigned int i, char c)
// {
// 	i = 0;
// 	return (c - 32);
// }

// int main()
// {
// 	char *str = "Hello World!";
// 	char *new_str = ft_strmapi(str, ft_test);
// 	printf("%s\n", new_str);
		// prints only Hello due to the null terminator (space - 32)
// 	return (0);
// }