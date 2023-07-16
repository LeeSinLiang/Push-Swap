/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:51:39 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 15:15:30 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_seperator(char c_str, char c)
{
	if (c_str == c)
		return (true);
	return (false);
}

static int	count_strings(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && check_seperator(*str, c))
			str++;
		if (*str)
			count++;
		while (*str && !check_seperator(*str, c))
			str++;
	}
	return (count);
}

// count string before character c
static int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_seperator(str[i], c))
		i++;
	return (i);
}

static char	*word(char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_strclen(str, c);
	word = (char *)malloc((len + 1) * 1);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)s;
	arr = (char **)malloc((count_strings(str, c) + 1) * 8);
	while (*str)
	{
		while (*str && check_seperator(*str, c))
			str++;
		if (*str)
		{
			arr[i] = word(str, c);
			i++;
		}
		while (*str && !check_seperator(*str, c))
			str++;
	}
	arr[i] = 0;
	return (arr);
}

// #include <stdio.h>
// int		main(int argc, char **argv)
// {
// 	int		index;
// 	char	**split;

// 	split = ft_split(argv[1], argv[2][0]);
// 	index = 0;
// 	printf("tab start\n");
// 	while (split[index])
// 	{
// 		printf("tab[%d]: $%s$\n", index, split[index]);
// 		fflush(stdout);
// 		index++;
// 	}
// 	printf("tab end\n");
// }
