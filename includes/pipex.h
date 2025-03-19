/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:36:37 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/19 16:01:17 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

// PIPE FUNCTIONS
void	ft_first_process(char **cmd, int fds[], int pipefd[], char *envp[]);
void	ft_child_process(char **cmd, int fds[], int pipefd[], char *envp[]);
void	ft_last_process(char **cmd, int fds[], char *envp[]);
int		ft_pipes(char *cmd, int fds[], char *envp[], int first_last[]);

// UTILS
void	free_matrix(char **envp);
char	**ft_get_environment(char **envp);
char	*ft_get_path(char **envp, char *cmnd);
int		ft_access_rights(char *inputfile, char *outputfile);
int		ft_access_rights_bonus(char *inputfile, char *outputfile);
void	error_pipex(char c);
int		get_first_arg(char *argv[]);
void	read_input_limiter(int i, char *argv[]);
char	**ft_set_global_path(void);
void	ft_err_msg(int error, char **path);

// Bonus
void	del_heredoc(char *argv[]);
#endif // PIPEX_H
