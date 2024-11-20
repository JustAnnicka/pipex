/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/20 17:51:55 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
MUST TAKE 4 ARGUMENTS
-> ./pipex file1 cmd1 cmd2 file2
--> file1 and file2 are file names.
--> cmd1 and cmd2 are shell commands with their parameters.

You have to turn in a Makefile which will compile your source files. It must 
not relink.
• You have to handle errors thoroughly. In no way your program should quit
unexpectedly (segmentation fault, bus error, double free, and so forth).
• Your program mustn’t have memory leaks.
• If you have any doubt, handle the errors like the shell command:
< file1 cmd1 | cmd2 > file2


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


STEPS TO TAKE
-> Check # of argc
-> get all cmds in listed and save the (FT_Split)
-> When using here_doc (bonus) the second cmd is not a file

RANDOM STUFF
STDIN IS FD 0
STDOUT IS FD 1

POOSIBLE WAY TO DO THIS
create a structture that hold a matrix with following data
-> **char of a copy of the content of the inputfile
-> *char[] of the argv (maybe newarg with only the cmnds)
	-> in case of newargv use *char for the outputfile
	-> in case of newargv use a bool to determine here_doc
	-> in case of newargc use a *char to store LIMITER
-> PID (also ParentPID?)
-> Int array with (maybe List type as we can add to this or calloc allocated by cmd count)
	-> Read end
	-> Write end
*/
int	ft_access_rights(char *inputfile, char *outputfile)
{
	int	fd;

	fd = access(inputfile, R_OK);
	if (fd < 0)
		perror("Input file error\nDescription");
	fd = access(outputfile, W_OK);
	if (fd < 0 && errno != 2)
		perror("Output file error\nDescription");
	if (errno == 2)
		fd = 0;
	return (fd);
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
	//static char	**newargv;

	if (argc < 5)
		return (argv = NULL, ft_printf("Wrong argument count"), -1);
	if (ft_access_rights(argv[1], argv[argc - 1]) < 0)
		return (argv = NULL, -1);
	printf("argv: %s", argv[0]);
	//printf("\nSTDIN: %d", STDIN);
/* 	newargv = ft_calloc(argc, sizeof (char**));
	if (!newargv)
		return (-1);
	while (--argc > 0)
		newargv[argc - 1] = argv[argc];
	while (newargv[argc++] != NULL) 
		printf("\nnewargv: %s", newargv[argc - 1]); */
	/*execve(argv[0], argv, NULL);
	perror("execve");
	exit(EXIT_FAILURE); */
	return (0);
}
