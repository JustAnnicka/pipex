/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:23:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/19 16:04:32 by aehrl            ###   ########.fr       */
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
-> 
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

int	main(int argc, char *argv[])
{
	if (argc < 5)
		return (argv = NULL, ft_printf("Wrong argument count"), -1);
	if (ft_access_rights(argv[1], argv[argc - 1]) < 0)
		return (argv = NULL, -1);
	printf("test: %s", argv[argc - 1]);
	return (0);
}