/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:31:51 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/03 15:32:21 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implements ft_putendl_fd function: 
// output string to file descriptor with newline

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd(10, fd);
}
