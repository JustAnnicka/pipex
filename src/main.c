/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/12/05 17:45:19 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
MUST TAKE 4 ARGUMENTS
-> ./pipex file1 cmd1 cmd2 file2
--> file1 and file2 are file names.
--> cmd1 and cmd2 are shell commands with their parameters.

Bonus part
You will get extra points if you:
• Handle multiple pipes.
This:
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
Should behave like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
• Support « and » when the first parameter is "here_doc".
This:
$> ./pipex here_doc LIMITER cmd cmd1 file
Should behave like:


The | (pipe) symbol redirects the output of the command on the left to the input of the command on the right.

In that case, the | symbol redirects the output of the grep command to the input of the wc command.

ERROR HANDLING:
-> less than 4 arguments [DONE]
-> No input file (manditory) [DONE]
-> Check read permissions input [DONE]
-> Check write permissions output file [DONE]
-> No Limiter (bonus)
-> no output file [DONE]
*/
int	ft_access_rights(char *inputfile, char *outputfile)
{
	int	x;
	
	x = access(outputfile, W_OK);
	if (x < 0 && errno != 2)
		return (perror("Output file error\nDescription"), -1);
	x = access(inputfile, R_OK);
	if (x < 0)
		return (perror("Input file error\nDescription"), -1);
	return (x);
}

/* int	ft_pipes(char *cmd, int fd_in, int fd_out, int is_last)
{
	int			pipefd[2];
	pid_t		pid;

	if (!is_last && pipe(pipefd) < 0) {
        perror("Error creating pipe");
        return -1;
    }
	pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        return -1;
    }
	if (pid == 0)
	{
		if (fd_in != STDIN_FILENO) {
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		if (is_last) {
			dup2(fd_out, STDOUT_FILENO);
		} else {
			dup2(pipefd[1], STDOUT_FILENO);
		}
		if (!is_last) {
			close(pipefd[0]);
			close(pipefd[1]);
		}
		close(fd_out);
		char **cmd_args = ft_split(cmd, ' ');
		if (execve(cmd_args[0], cmd_args, NULL) < 0) {
			perror("Error executing command");
			exit(1);
		}
		if (fd_in != STDIN_FILENO) close(fd_in); 
		if (!is_last)
		{
			close(pipefd[1]);
			fd_in = pipefd[0];
		}
	}
	waitpid(pid, NULL, 0);
	return (is_last ? 0 : fd_in);
} */
int	ft_child(char **cmnd, int fds[], int pipefd[], char *envp[])
{
	if (fds[0] != STDIN_FILENO)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fds[1]);
	if (execve(ft_get_path(envp, cmnd[0]), cmnd, envp) < 0) 
	{
			perror("Error executing command");
			exit(1);
	}
	if (fds[0] != STDIN_FILENO)
		close(fds[0]); 
	close(pipefd[1]);
	fds[0] = pipefd[0];
	return (fds[0]);
}

int	ft_last_process(char **cmnd, int fds[], char *envp[])
{
	//ft_printf("fd_out:%d\n", fds[1]);
	//dup2(fds[1], STDOUT_FILENO);
	if (dup2(fds[1], fds[2]) < 0)
	{
		perror("dup2 failed");
		exit(1);
	}
	/* fprintf(stderr, "after dup2: fd_out:%d\n", fds[1]);
	fprintf(stderr,"after dup2: cmnd:%s\n", cmnd[1]); */
	//write(STDOUT_FILENO, "HELLO", 5);
	char *path = ft_get_path(envp, cmnd[0]);
	if (execve(path, cmnd, envp) < 0) 
	{
			perror("Error executing command");
			exit(1);
	}
	fprintf(stderr, "path:%s\n", ft_get_path(envp, cmnd[0]));
	if (fds[0] != STDIN_FILENO)
		close(fds[0]); 
	return (0);
}

int ft_pipes(char *cmnd, int fds[], char *envp[], int is_last)
{
	pid_t	pid;
	int		pipefd[2];
	char	**cmd;

	cmd = ft_split(cmnd, ' ');
	if (is_last != 1 && pipe(pipefd) < 0)
        return (perror("Error creating pipe"), -1);
	pid = fork();
	if (pid < 0) 
		return (perror("Error forking process"), -1);
	if (pid == 0)
	{
		if (is_last != 1)
		{
			close(pipefd[0]);
			ft_child(cmd, fds, pipefd, envp);
		}
		else
			ft_last_process(cmd, fds, envp);
	}
	if (is_last != 1)
	{
        close(pipefd[1]);
        close(fds[0]);
        fds[0] = pipefd[0];
    }
	ft_printf("fd_out:%d\n", fds[1]);
	close(fds[1]);
	//ft_printf("STDOUT:%d\n",  STDOUT_FILENO);
	waitpid(pid, NULL, 0);
	if (is_last == 1)
		return (-1);
	return (fds[0]);
}

/* int	main(int argc, char *argv[])
{
	int		count;
	int		fd_in;
	int		fd_out;
	int		fd_temp;
	int		is_last;
	
	count = 2;
	fd_in = 0;
	fd_out = 1;
	if (argc < 5)
		return (argv = NULL, ft_printf("Wrong argument count"), -1);
	if (ft_strncmp(argv[count - 1], "here_doc", ft_strlen(argv[count - 1])) == 0)
		count++;
	if (count == 2 && (ft_access_rights(argv[count - 1], argv[argc - 1]) < 0))
		return (argv = NULL, -1);
	if (count == 2)
		fd_in = open(argv[count - 1], O_RDONLY | O_CLOEXEC);
	fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_CLOEXEC,  S_IRWXU);
	while (count < argc - 1)
	{
		is_last = (count == argc - 2);
		fd_temp = ft_pipes(argv[count], fd_in, fd_out, is_last);
		if (fd_temp < 0)
		{
			close(fd_out);
			return (1);
		}
		fd_in = fd_temp;
		count++;
	}
	close(fd_out);
	return (0);
} */

int	main(int argc, char *argv[], char *envp[])
{
	int		count;
	int		fds[3];
	int		fd_temp;
	int		is_last;
	
	count = 2;
	is_last = 0;
	if (argc < 5)
		return (argv = NULL, ft_printf("Wrong argument count"), -1);
	if (ft_strncmp(argv[count - 1], "here_doc", ft_strlen(argv[count - 1])) == 0)
		count++;
	if (count == 2 && (ft_access_rights(argv[count - 1], argv[argc - 1]) < 0))
		return (argv = NULL, -1);
	if (count == 2)
		fds[0] = open(argv[count - 1], O_RDONLY | O_CLOEXEC);
	fds[2] = open(argv[argc - 1], O_RDWR | O_CREAT | O_CLOEXEC ,  S_IRWXU);
	ft_printf("output fd:%d\n", fds[2]);
	fds[1] = STDOUT_FILENO;
	envp = ft_get_environment(envp);
	while (count < argc - 1)
	{
		if (count == argc - 2)
			is_last = 1;
		fd_temp = ft_pipes(argv[count], fds, envp, is_last);
		ft_printf("fd_temp:%d\n", fd_temp);
		if (fd_temp < 0)
		{
			close(fds[1]);
			return (0);
		}
		fds[1] = fd_temp;
		count++;
	}
	return (0);
}
