/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:46:47 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/09 16:32:12 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Orig: %c, Mine: %c\n" toupper('a'), ft_toupper('a'));
	printf("Orig: %c, Mine: %c\n" toupper('V'), ft_toupper('V'));
	printf("Orig: %c, Mine: %c\n" toupper('.'), ft_toupper('.'));
	return (0);
}
*/
