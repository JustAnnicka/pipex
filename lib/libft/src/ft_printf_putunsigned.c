/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:58 by aehrl             #+#    #+#             */
/*   Updated: 2024/07/15 16:05:31 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printf_putunsigned((long long)n / 10);
		count += ft_printf_putunsigned((long long)n % 10);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
		count++;
	}
	return (count);
}
