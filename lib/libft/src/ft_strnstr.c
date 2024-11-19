/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:36:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/12 16:33:42 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		j = 0;
		while (*(haystack + j) == *(needle + j)
			&& *(needle + j) && j <= len)
		{
			if (!*(needle + j + 1))
				return ((char *)haystack);
			j++;
		}
		haystack++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "aaabcdabcde";
// 	char *s2 = "MZIRIBMZE";
 //	size_t max = strlen(s2);
 	char *i1 = strnstr(s1, "abcde", 11);
 	char *i2 = ft_strnstr(s1, "abcde", 11);

	printf("Orig: %s", i1);
	printf("\nMine: %s", i2);
	return (0);
}
*/