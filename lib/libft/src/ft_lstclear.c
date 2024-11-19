/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:28:24 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/08 13:48:27 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;

	cpy = *lst;
	while ((*lst) != NULL)
	{
		cpy = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = cpy;
	}
	free((*lst));
	*lst = NULL;
}
