/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/19 18:58:09 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_first_process(char **cmd, int fds[], int pipefd[], char *envp[])
{
	if (fds[0] != STDIN_FILENO)
	{
		if (dup2(fds[0], STDIN_FILENO) < 0)
		{
			perror("Error redirecting input");
			exit(1);
		}
		close(fds[0]);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(fds[0]);
	close(fds[1]);
	if (execve(ft_get_path(envp, cmd[0]), cmd, envp) < 0)
	{
		perror("Error\nexecuting command");
		exit (1);
	}
	return (-1);
}

int	ft_child_process(char **cmd, int fds[], int pipefd[], char *envp[])
{
	if (fds[0] != STDIN_FILENO)
	{
        if (dup2(fds[0], STDIN_FILENO) < 0)
		{
            perror("Error redirecting input");
            exit(1);
        }
        close(fds[0]);
    }
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    if (execve(ft_get_path(envp, cmd[0]), cmd, envp) < 0)
	{
        perror("Error\nexecuting command");
        exit(1);
    }
    return (-1);
}

int	ft_last_process(char **cmd, int fds[], char *envp[])
{
	if (fds[0] != STDIN_FILENO)
	{
		if (dup2(fds[0], STDIN_FILENO) < 0)
		{
			perror("Error redirecing input");
			exit(1);
		}
		close(fds[0]);
	}
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	if (execve(ft_get_path(envp, cmd[0]), cmd, envp) < 0)
	{
        perror("Error executing command");
        exit(1);
    }
    return (-1);
}

int ft_pipes(char *cmd, int fds[], char *envp[], int is_first, int is_last)
{
	pid_t	pid;
	int		pipefd[2];

	if (!is_last && pipe(pipefd) < 0)
		return (perror("Error creating pipe"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Error forking process"), -1);
	if (pid == 0)
	{
		if (is_first == 2)
			ft_first_process(ft_split(cmd, ' '), fds, pipefd, envp);
		else if (is_last)
			ft_last_process(ft_split(cmd, ' '), fds, envp);
		else
			ft_child_process(ft_split(cmd, ' '), fds, pipefd, envp);
	}
	if (!is_last)
	{
		close(pipefd[1]);
		fds[0] = pipefd[0];
	}
	waitpid(pid, NULL, 0); // IF ITS HEAD DONT WAIT but exit
	return (fds[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		count;
	int		fds[2];
	int		is_last;
	
	count = get_first_arg(argv);
	if (argc < 5)
		return (argv = NULL, error_pipex('a'), -1);
	if (ft_access_rights_bonus(argv[count], argv[argc - 1]) < 0) 
		return (argv = NULL, -1);
 	if (ft_strncmp(argv[count], "here_doc", ft_strlen(argv[count])) == 0)
		read_input_limiter(count, argv);
	fds[0] = open(argv[count], O_RDONLY);
	if (ft_strncmp(argv[count], "here_doc", ft_strlen(argv[count])) == 0)
		count = count + 2;
	fds[1] = open(argv[argc - 1], O_RDWR | O_CREAT, S_IRWXU);
	is_last = 0;
	envp = ft_get_environment(envp);
	while (++count < argc - 1)
	{
		if (count == argc - 2)
			is_last = 1;
		if (ft_pipes(argv[count], fds, envp, count, is_last) < 0)
			return (close(fds[0]), close(fds[1]), 1);
	}
	return (free_matrix(envp), close(fds[0]), close(fds[1]), 0);
}
