/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/19 16:06:50 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_set_global_path(void)
{
	char	**path;
	char	*aux;

	aux = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	path = ft_split(aux, ':');
	return (path);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		first_last[2];
	int		fd[3];
	char	**aux;

	first_last[0] = 2;
	if (argc != 5)
		return (ft_printf("Error\nUsage: infile cmd1 cmd2 ... outfile\n"), -1);
	if (ft_access_rights(argv[first_last[0] - 1], argv[argc - 1]) < 0)
		exit(2);
	fd[0] = open(argv[first_last[0] - 1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	first_last[1] = 0;
	aux = ft_get_environment(envp);
	while (first_last[0] < argc - 1)
	{
		if (first_last[0] == argc - 2)
			first_last[1] = 1;
		fd[2] = ft_pipes(argv[first_last[0]], fd, aux, first_last);
		if (fd[2] != 0)
			return (close(fd[0]), close(fd[1]), ft_err_msg(fd[2], aux), fd[2]);
		first_last[0]++;
	}
	return (free_matrix(aux), close(fd[0]), close(fd[1]), 0);
}
