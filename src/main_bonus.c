/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/19 16:08:59 by aehrl            ###   ########.fr       */
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

void	ft_check_input(int argc, char **argv, int fst_arg)
{
	if (argc < 5)
	{
		ft_printf("Error\nUsage: infile cmd1 cmd2 ... outfile\n");
		exit(2);
	}
	if (ft_access_rights_bonus(argv[fst_arg], argv[argc - 1]) < 0)
	{
		argv = NULL;
		exit(errno);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		f_l[2];
	int		fd[3];
	char	**aux;

	f_l[0] = get_first_arg(argv);
	ft_check_input(argc, argv, f_l[0]);
	if (ft_strncmp(argv[f_l[0]], "here_doc", ft_strlen(argv[f_l[0]])) == 0)
		read_input_limiter(f_l[0], argv);
	fd[0] = open(argv[f_l[0]], O_RDONLY);
	if (ft_strncmp(argv[f_l[0]], "here_doc", ft_strlen(argv[f_l[0]])) == 0)
		f_l[0] = f_l[0] + 1;
	fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	f_l[1] = 0;
	aux = ft_get_environment(envp);
	while (aux != NULL && ++f_l[0] < argc - 1)
	{
		if (f_l[0] == argc - 2)
			f_l[1] = 1;
		fd[2] = ft_pipes(argv[f_l[0]], fd, aux, f_l);
		if (fd[2] < 0)
			return (close(fd[0]), close(fd[1]), ft_err_msg(fd[2], aux), fd[2]);
	}
	return (free_matrix(aux), close(fd[0]), close(fd[1]), 0);
}
