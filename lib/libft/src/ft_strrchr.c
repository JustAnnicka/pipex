/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:48:21 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/06 17:01:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	char	x;
	size_t	i;

	x = (char)c;
	i = ft_strlen(s);
	src = (char *)&s[i];
	if (x == '\0')
		return (src);
	while (i-- > 0)
	{
		src--;
		if (s[i] == x)
		{
			return (src);
		}
	}
	return (0);
}
