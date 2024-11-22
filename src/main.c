/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/22 15:42:28 by aehrl            ###   ########.fr       */
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
-> Check write permissions output file
-> No Limiter (bonus)
-> no output file 

RANDOM STUFF
STDIN IS FD 0
STDOUT IS FD 1

start by doing an open to get fd of infile
make sure we can write to outfile or create it (Open with create flag) with correct permissions
then we can fork, dup2, and pipe
we need the cmnds to be split into an array so that each flag is its own string that can be checked by excev
finally we excev the programm
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

/* int	ft_pipes(char **argv)
{
	//CREATE ***MATRIX TO STORE READ AND WRITE ENDS OF PIPES OF THE WHOLE CMNDS?
	//int pipe(int pipefd[2]);

} */

/* int	ft_forks(char **argv)
{
	pid_t fork(void);
} */

int	main(int argc, char *argv[])
{
	char	**cmnd;
	int		count;
	int		fd_in;
	int		fd_out;
	pid_t pid;

	count = 2;
	fd_in = 0;
	fd_out = 1;
	if (argc < 5)
		return (argv = NULL, ft_printf("Wrong argument count"), -1);
	if (ft_strncmp(argv[count - 1], "here_doc", ft_strlen(argv[count])) == 0)
		count++;
	if (count == 2 && (ft_access_rights(argv[count - 1], argv[argc - 1]) < 0))
		return (argv = NULL, -1);
	if (count == 2)
		fd_in = open(argv[count - 1], O_RDONLY | O_CLOEXEC);
	fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_CLOEXEC,  S_IRWXU);
	ft_printf("fd in: %d  fd out: %d\n", fd_in, fd_out);
	while (count < argc - 1)
	{
		int i = 0;
		cmnd = ft_split(argv[count], '-');
		while(cmnd[i])
		{
			ft_printf("cmnd[%d]: %s\n", i, cmnd[i]);
			i++;
		}
		//maybe free cmnd
	//	execve(argv[0], cmnd, NULL);
		count++;
	}
	pid = fork();
	if (pid < 0)
		return (ft_printf("fork error"), perror("Output file error\nDescription"), -1); 
	//waitpid(pid);
	ft_printf("pid: %d\n", pid);
	/*execve(argv[0], argv, NULL);
	perror("execve");
	exit(EXIT_FAILURE); */
	return (0);
}
