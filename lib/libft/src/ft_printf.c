/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manditory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:42:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/07/15 16:13:00 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_check(va_list args, const char *format)
{
	if (*format == 'c')
		return (ft_printf_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_printf_putaddress(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_printf_putnbr(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_printf_putunsigned(va_arg(args, unsigned long)));
	else if (*format == 'x' || *format == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), *format));
	else if (*format == '%')
		return (ft_printf_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_printf_check(args, format);
		}
		else
			count += ft_printf_putchar(*format);
		if (count < 0)
			return (-1);
		format++;
	}
	va_end(args);
	return (count);
}

/* 	#include <stdio.h>
 *  	hello
int	main(void)
{
 	void		*ptr;
	//char		s[] = "Hello";
	long long	lng = 9223372036854775807L; 

	ptr = &lng;
 	ft_printf("ft_printf count: %d\n", ft_printf(" %p ", ptr));
	printf("printf count: %d\n\n", printf(" %p ", ptr)); 
    ft_printf("ft_printf count: %d\n", ft_printf("chr: %c \ns: %s\n",'b', "s"));
	printf("printf count: %d\n\n", printf("chr: %c \ns: %s\n",'b', "s")); 
	
	ft_printf("ft_printf count: %d\n", ft_printf("hex: %x & %x\n", 1560, 720));
	printf("printf count: %d\n\n", printf("hex: %x & %x\n", 1560, 720));

	ft_printf("ft_printf ptr count: %d\n", ft_printf("void *: %p\n", ptr));
	printf("printf hex ptr: %d\n\n", printf("void *: %p\n", ptr)); 

	ft_printf("ft_printf count: %d\n", ft_printf("dec: %d\nint: %i\n", -10, 15));
	printf("printf count: %d\n\n", printf("dec: %d\nint: %i\n", -10, 15));
	
	ft_printf("ft_printf unsigned: %d\n", ft_printf("unsigned: %u\n", 42949));
	printf("printf unsigned: %d\n\n", printf("unsigned: %ld\n", 42949));

	ft_printf("ft_printf count: %d\n", ft_printf("percentage: %i%%\n", 99));
	printf("printf count: %d\n\n", printf("percentage: %i%%\n", 99));      

	ft_printf("ft_printf count: %d\n", ft_printf(" %04d ", -14));
	printf("printf count: %d\n\n", printf(" %04d ", -14));   

	return(0);
}*/
