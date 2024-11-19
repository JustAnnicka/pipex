/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:51:24 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 19:09:15 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_number(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	int			x;

	i = ft_count_number(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		n = n * -1;
	}
	while (i-- != 0 && str[i] == 0)
	{
		x = n % 10;
		n = n / 10;
		str[i] = x + '0';
	}
	return (str[ft_strlen(str)] = '\0', str);
}

/* #include <stdio.h>

int	main(void)
{
	int	n;

	n = -500;
	printf("%s", ft_itoa(n));
	return (0);
}
 */