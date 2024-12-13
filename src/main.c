/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/12/13 18:43:19 by aehrl            ###   ########.fr       */
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
		perror("Error executing command");
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
        perror("Error executing command");
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
	dup2(fds[1], STDOUT_FILENO); // dup the output file to STDOUT
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
	char	**cmd_split;

	cmd_split = NULL;
	if (!is_last && pipe(pipefd) < 0)
		return (perror("Error creating pipe"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Error forking process"), -1);
	if (pid == 0) // child process
	{
		cmd_split = ft_split(cmd, ' ');
		if (is_first == 2)
			ft_first_process(cmd_split, fds, pipefd, envp);
		else if (is_last)
			ft_last_process(cmd_split, fds, envp);
		else
			ft_child_process(cmd_split, fds, pipefd, envp);
	}
	// parent process: close unused ends
	if (!is_last)
	{
		close(pipefd[1]);
		if (fds[0] != STDIN_FILENO)
			close (fds[0]);
		fds[0] = pipefd[0];
	}
	waitpid(pid, NULL, 0);
	return (fds[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		count;
	int		fds[2];
	int		fd_temp;
	int		is_last;
	
	count = 2;
	is_last = 0;
	if (argc < 5)
		return (argv = NULL, ft_printf("Usage: %s infile cmd1 cmd2 ... outfile\n", argv[0]), -1);
	if (count == 2 && (ft_access_rights(argv[count - 1], argv[argc - 1]) < 0))
		return (argv = NULL, -1);
	if (count == 2)
		fds[0] = open(argv[count - 1], O_RDONLY);
	fds[1] = open(argv[argc - 1], O_RDWR | O_CREAT ,  S_IRWXU);
	ft_printf("output fd:%d\n", fds[1]);
	envp = ft_get_environment(envp);
	while (count < argc - 1)
	{
		if (count == argc - 2)
			is_last = 1;
		fd_temp = ft_pipes(argv[count], fds, envp, count, is_last);
		ft_printf("fd_temp:%d\n", fd_temp);
		if (fd_temp < 0)
		{
			close(fds[0]);
			close(fds[1]);
			return (1);
		}
		count++;
	}
	close(fds[0]);
	close(fds[1]);
	return (0);
}
