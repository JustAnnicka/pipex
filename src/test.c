
#include "../includes/pipex.h"

int	main(int argc, char *argv[])
{
	static char *newargv[] = { NULL, "hello", "world", NULL };
	static char *newenviron[] = { NULL };

	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	newargv[0] = argv[1];
	execve(argv[1], newargv, newenviron);
	perror("execve");
	exit(EXIT_FAILURE);
}
/* 
           $ cc myecho.c -o myecho
           $ cc execve.c -o execve
           $ ./execve ./myecho
           argv[0]: ./myecho
           argv[1]: hello
           argv[2]: world */
		   
/* int	main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		return (-1);
	fd = access(argv[1], F_OK);
	if (fd < 0)
	{
		ft_printf("Error number: %d\n", errno);
		perror("Error description");
	}
	else
		ft_printf("No error\n");
	return (0);
} */

/* int main(void) 
{
	printf("Hello, world!\n");
	return (0);
}
 */