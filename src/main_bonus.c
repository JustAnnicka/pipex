/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/25 18:33:15 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	f_l[2];
	int	fds[2];

	f_l[0] = get_first_arg(argv);
	if (argc < 5)
		return (ft_printf("Error\nUsage: infile cmd1 cmd2 ... outfile\n"), -1);
	if (ft_access_rights_bonus(argv[f_l[0]], argv[argc - 1]) < 0)
		return (argv = NULL, -1);
	if (ft_strncmp(argv[f_l[0]], "here_doc", ft_strlen(argv[f_l[0]])) == 0)
		read_input_limiter(f_l[0], argv);
	fds[0] = open(argv[f_l[0]], O_RDONLY);
	if (ft_strncmp(argv[f_l[0]], "here_doc", ft_strlen(argv[f_l[0]])) == 0)
		f_l[0] = f_l[0] + 1;
	fds[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	f_l[1] = 0;
	envp = ft_get_environment(envp);
	while (++f_l[0] < argc - 1)
	{
		if (f_l[0] == argc - 2)
			f_l[1] = 1;
		if (ft_pipes(argv[f_l[0]], fds, envp, f_l) < 0)
			return (close(fds[0]), close(fds[1]), 1);
		del_heredoc(argv);
	}
	return (free_matrix(envp), close(fds[0]), close(fds[1]), 0);
}
