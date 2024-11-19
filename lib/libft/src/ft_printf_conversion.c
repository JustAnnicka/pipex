/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:35:59 by aehrl             #+#    #+#             */
/*   Updated: 2024/07/15 16:05:08 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conversion(int format)
{
	if (format == 'x')
		return (ft_printf_putstr("0x"));
	else if (format == 'X')
		return (ft_printf_putstr("0X"));
	return (-1);
}
