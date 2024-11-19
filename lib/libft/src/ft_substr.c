/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:46:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 19:10:11 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string;
	size_t		i;	

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	string = ft_calloc(len + 1, sizeof(const char));
	if (!string)
	{
		errno = 12;
		return (NULL);
	}
	while (i < len && s[start + i] != '\0')
	{
		string[i] = s[i + start];
		i++;
	}
	string[len] = '\0';
	return (string);
}
