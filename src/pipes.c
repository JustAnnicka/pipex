/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:17:08 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/23 20:17:27 by aehrl            ###   ########.fr       */
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
		exit(1);
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

int	ft_pipes(char *cmd, int fds[], char *envp[], int first_last[])
{
	pid_t	pid;
	int		pipefd[2];

	if (!first_last[1] && pipe(pipefd) < 0)
		return (perror("Error\n creating pipe"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("Error\n forking process"), -1);
	if (pid == 0)
	{
		if (first_last[0] == 2)
			ft_first_process(ft_split(cmd, ' '), fds, pipefd, envp);
		else if (first_last[1])
			ft_last_process(ft_split(cmd, ' '), fds, envp);
		else
			ft_child_process(ft_split(cmd, ' '), fds, pipefd, envp);
	}
	if (!first_last[1])
	{
		close(pipefd[1]);
		fds[0] = pipefd[0];
	}
	waitpid(pid, NULL, 0);
	return (fds[0]);
}