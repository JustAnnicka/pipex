/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:10:55 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/09 16:34:24 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Start file
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Include Libraries
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

//Define typedef structure
typedef struct s_flags
{
	int	space;
	int	plus;
	int	minus;
	int	digit;
	int	sharp;
	int	dot;
	int	zero;
}		t_flags;

//Call Functions
int	ft_printf(const char *format, ...);

//Character / String Functions
int	ft_printf_putchar(int c);
int	ft_printf_putstr(char *s);

//Digit functions
int	ft_printf_putnbr(int n);
int	ft_printf_putunsigned(unsigned int n);

//Helper functions
int	ft_printf_putaddress(void *addr);
int	ft_printf_hex(unsigned int n, int format);
int	ft_printf_countnbr(long long n, int div);
int	ft_printf_countnbr_unsigned(unsigned int n, int div);
int	ft_printf_conversion(int format);
//End file
#endif