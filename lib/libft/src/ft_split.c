/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:48:50 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/24 14:30:41 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letters(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

static size_t	ft_count(const char *s, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

void	ft_free(char **array, size_t i)
{
	while (i > 0)
		free(array[i--]);
	free(array);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	array = (char **)ft_calloc(ft_count(&s[i], c) + 1, sizeof(const char *));
	if (!array)
		return (free(array), NULL);
	while (s[start] != '\0' )
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] != c && s[start] != '\0')
		{
			array[i] = ft_substr(s, start, ft_count_letters(&s[start], c));
			if (!(array[i]))
				ft_free(array, i);
			start = start + ft_count_letters(&s[start], c);
			i++;
		}
	}
	return (array[i] = NULL, array);
}
