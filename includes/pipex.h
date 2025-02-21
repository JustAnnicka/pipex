
#ifndef PIPEX_H
# define PIPEX_H
//# ifndef	STDIN
//#  define STDIN 0
//# endif
//# ifndef STDOUT
//#  define STDOUT 1
//# endif
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

void	free_matrix(char **envp);
char	**ft_get_environment(char **envp);
char	*ft_get_path(char **envp, char *cmnd);
int		ft_access_rights(char *inputfile, char *outputfile);
int		ft_access_rights_bonus(char *inputfile, char *outputfile);
void	error_pipex(char c);
int		get_first_arg(char *argv[]);
void 	read_input_limiter(int i, char *argv[]);

#endif // PIPEX_H
