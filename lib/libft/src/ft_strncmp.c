/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:11:39 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/06 17:01:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (n-- > 0)
	{
		if (c1[i] != c2[i])
		{
			if (c1[i] > c2[i] || (c1[i] != '\0' && c2[i] == '\0'))
				return (1);
			else if (c1[i] < c2[i] || (c1[i] != '\0' && c1[i] == '\0'))
				return (-1);
		}
		else if (c1[i] == '\0' && c2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
