/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:19:02 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/08 17:04:28 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (d < s)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[16] = "This is my dest";
	char src[] = "Lets change the text";
	int	dest_int[] = {0, 0, 0, 0, 0, 0};
   	int src_int[] = {42, 42, 42, 42, 42, 42};
	char dest_2[16] = "This is my dest";
	char src_2[] = "Lets change the text";
	int i;
	int n;

	n = 6;
	printf("Dest before memmove \n%s", dest);
	memmove(dest, src, strlen(src)+1);
	printf("\nDest after memmove\n%s", dest);
	i = 0;
	printf("\nDest_int before memmove\n");
	while (i < n)
	{
		printf("%d, ", dest_int[i]);
		i++;
	}
	memmove(dest_int, src_int, sizeof(src_int));
	printf("\nDest_int after memmove\n");
	i = 0;
	while (i < n)
	{
		printf("%d, ", dest_int[i]);
		i++;
	}
	printf("\n\nDest_2 before ft_memmove \n%s", dest_2);
    ft_memmove(dest_2, src_2, strlen(src_2)+1);
    printf("\nDest_2 after ft_memmove\n%s", dest_2);
	return (0);	
}
*/
