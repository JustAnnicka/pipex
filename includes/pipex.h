
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

char	**ft_get_environment(char **envp);
char	*ft_get_path(char **envp, char *cmnd);
int		ft_access_rights(char *inputfile, char *outputfile);

#endif // PIPEX_H
