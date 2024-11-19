/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:10:01 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/18 18:49:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	j;

	j = 0;
	while (j < argc)
	{
		printf("argv[%d]: %s\n", j, argv[j]);
		j++;
	}
	exit(EXIT_SUCCESS);
}