/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/18 20:33:34 by aehrl            ###   ########.fr       */
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
	//close(fds[1]); NEED TO CLOSE HERE??
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
            perror("Error\nredirecting input");
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
			perror("Error\nredirecing input");
			exit(1);
		}
		close(fds[0]);
	}
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	if (execve(ft_get_path(envp, cmd[0]), cmd, envp) < 0)
	{
        perror("Error\nexecuting command");
        exit(1);
    }
    return (-1);
}

int ft_pipes(char *cmd, int fds[], char *envp[], int is_first, int is_last)
{
	pid_t	pid;
	int		pipefd[2];

	if (!is_last && pipe(pipefd) < 0)
		return (perror("Error\n creating pipe"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Error\n forking process"), -1);
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
	waitpid(pid, NULL, 0);
	return (fds[0]);
}
int	main(int argc, char *argv[], char *envp[])
{
	int		count;
	int		fds[2];
	int		is_last;
	
	count = 2;
	if (argc < 5)
		return (error_pipex('a'), free_matrix(argv), -1);
	if (ft_access_rights(argv[count - 1], argv[argc - 1]) < 0) 
		return (argv = NULL, -1);
	fds[0] = open(argv[count - 1], O_RDONLY);
	fds[1] = open(argv[argc - 1], O_RDWR| O_CREAT | O_TRUNC , S_IRWXU);
	is_last = 0;
	envp = ft_get_environment(envp);
	while (count < argc - 1)
	{
		if (count == argc - 2)
			is_last = 1;
		if (ft_pipes(argv[count], fds, envp, count, is_last) < 0)
			return (close(fds[0]), close(fds[1]), 1);
		count++;
	}
	return (free_matrix(envp), close(fds[0]), close(fds[1]), 0); //NEED TO CLOSE AGAIN??
}
