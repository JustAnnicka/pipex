/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:48:23 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/07 17:09:51 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		end;
	t_list	*position;

	if (!lst)
		return (NULL);
	end = ft_lstsize(lst);
	position = lst;
	while (--end > 0)
		position = position->next;
	return (position);
}
