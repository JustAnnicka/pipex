/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:56:59 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/08 19:32:03 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	check;

	i = 0;
	x = 0;
	check = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == 45)
		check = -1;
	if ((str[i] == 43 || str[i] == 45))
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		x = (x * 10) + (str[i] - 48);
		i++;
	}
	return (x * check);
}
