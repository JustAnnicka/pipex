
#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

//PIPE FUNCTIONS
int		ft_first_process(char **cmd, int fds[], int pipefd[], char *envp[]);
int		ft_child_process(char **cmd, int fds[], int pipefd[], char *envp[]);
int		ft_last_process(char **cmd, int fds[], char *envp[]);
int		ft_pipes(char *cmd, int fds[], char *envp[], int first_last[]);

//UTILS
void	free_matrix(char **envp);
char	**ft_get_environment(char **envp);
char	*ft_get_path(char **envp, char *cmnd);
int		ft_access_rights(char *inputfile, char *outputfile);
int		ft_access_rights_bonus(char *inputfile, char *outputfile);
void	error_pipex(char c);
int		get_first_arg(char *argv[]);
void 	read_input_limiter(int i, char *argv[]);

// Bonus
void del_heredoc(char *argv[]);
#endif // PIPEX_H
