/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:22:58 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/06 17:01:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[50] = "This is my source text";
	char dest[50] = "This is the dest text";
	char src2[50] = "This is my second source text";
	char dest2[50] = "This is the dest2 text";
	int	src_int[] = {1, 2, 3, 4, 5, 6};
	int	dest_int[] = {0, 0, 0, 0, 0, 0};
	int src_int2[] = {1, 2, 3, 4, 5, 6};
    int dest_int2[] = {0, 0, 0, 0, 0, 0};
	int i;

	i = 0;
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	printf("Before memcpy dest_int\n");
	while(i < 6)
	{
		printf("%d", dest_int[i]);
		i++;
	} 
	memcpy(dest_int, src_int, 7);
	printf("\nAfter memcpy dest_int \n");
    i = 0;
	while(i < 6)
    {
        printf("%d", dest_int[i]);
        i++;
    }
	printf("\n\nBefore ft_memcpy dest2 = %s\n", dest2);
	ft_memcpy(dest2, src2, sizeof(src2));
	printf("After ft_memcpy dest2 = %s\n", dest2);
	printf("Before memcpy dest_int2\n");
    i = 0;
	while(i < 6)
    {
        printf("%d", dest_int2[i]);
        i++;
    }
    ft_memcpy(dest_int2, src_int2, sizeof(src2));
    printf("\nAfter memcpy dest_int2 \n");
    i = 0;
    while(i < 6)
    {
        printf("%d", dest_int2[i]);
        i++;
    }
	return (0);
}
*/
