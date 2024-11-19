/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:09:07 by aehrl             #+#    #+#             */
/*   Updated: 2024/07/15 16:05:30 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printf_putstr("(null)"));
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}
