/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:46:28 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 18:48:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	i = 0;
	total_size = count * size;
	if (count == 0 || size == 0 || total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}
