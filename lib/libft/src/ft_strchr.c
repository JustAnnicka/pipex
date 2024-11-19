/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:40:04 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/09 16:31:43 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;
	char	*src;
	int		i;

	src = (char *)s;
	x = (char)c;
	i = 0;
	if (x == '\0')
	{
		while (s[i++] != '\0')
			src++;
		return (src);
	}
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return (src);
		i++;
		src++;
	}
	return (0);
}
