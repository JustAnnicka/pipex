/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:13:14 by aehrl             #+#    #+#             */
/*   Updated: 2024/07/15 16:05:30 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr(int n)
{
	int	count;

	count = ft_printf_countnbr(n, 10);
	if (n < 0)
		count++;
	ft_putnbr_fd(n, 1);
	return (count);
}
