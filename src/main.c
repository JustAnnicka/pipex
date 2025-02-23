/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/23 20:22:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	first_last[2];
	int	fds[2];

	first_last[0] = 2;
	if (argc < 5)
		return (ft_printf("Error\nUsage: infile cmd1 cmd2 ... outfile\n"), -1);
	if (ft_access_rights(argv[first_last[0] - 1], argv[argc - 1]) < 0)
		return (argv = NULL, -1);
	fds[0] = open(argv[first_last[0] - 1], O_RDONLY);
	fds[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	first_last[1]= 0;
	envp = ft_get_environment(envp);
	while (first_last[0] < argc - 1)
	{
		if (first_last[0] == argc - 2)
			first_last[1] = 1;
		if (ft_pipes(argv[first_last[0]], fds, envp, first_last) < 0)
			return (close(fds[0]), close(fds[1]), 1);
		first_last[0]++;
	}
	return (free_matrix(envp), close(fds[0]), close(fds[1]), 0);
}
