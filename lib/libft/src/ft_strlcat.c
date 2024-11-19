/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:49:50 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/06 17:01:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;

	dst_i = ft_strlen(dst);
	src_i = 0;
	if (dst_i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[src_i] != '\0' && src_i < dstsize - dst_i - 1)
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_i + src_i] = '\0';
	return (dst_i + ft_strlen(src));
}
