/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:33:35 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/09 16:31:15 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, int len)
{
	int				i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (len-- > 0)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	dest[15] = "THIS IS TEXT" ;
	char	*str;

	str = memset(dest, 100, 5);
	printf("%s\n", str);
	ft_memset(dest, 100, 5);
	printf("%s\n%s", dest, str);

	int	dest_int[] = {1, 2, 3, 4, 5, 6};
	int dest2[] = {1, 2, 3, 4, 5, 6};
	int	i;

	i = 0;
	memset(dest_int,  42, 5);
	printf("\nmemset dest_int\n");
	while (i < 5)
	{
		printf("%d, ", dest_int[i]);
		i++;
	}
	printf("\nMy Function:\n");
	i = 0;
	ft_memset(dest2, 42, 5);
	while (i < 5)
    {
        printf("%d, ", dest2[i]);
        i++;
    }

	return (0);
}
*/
