/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:04:05 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/09 16:05:46 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	chr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n-- > 0)
	{
		if (*src == chr)
			return (src);
		src++;
	}
	return (0);
}
