/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:14:55 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/05 19:05:43 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	if (s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (set && ft_strchr(set, (int)s1[start]) != 0)
		start++;
	while (set[i] != '\0')
	{
		if (s1[end] == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	i = end - start + 1;
	return (ft_substr(s1, start, i));
}

/*
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char s1[] = "";
	char set[] = "";
	char	*str2;

	str2 = ft_strtrim(s1, set);
	printf("Mine: %s\n", str2);
	return (0);
}
*/