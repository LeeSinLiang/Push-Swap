/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:17:03 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/05 17:21:56 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implements ft_lstdelone function:
// delete the node 'lst' with the function 'del'

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
