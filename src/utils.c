/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:05 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/19 16:08:00 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_access_rights(char *inputfile, char *outputfile)
{
	int	i;
	int	o;

	i = access(inputfile, R_OK);
	if (i < 0)
		ft_err_msg(errno, NULL);
	o = access(outputfile, W_OK);
	if (o < 0 && (errno != 2 || ft_strlen(outputfile) == 0))
		ft_err_msg(errno, NULL);
	if (errno == 2 && ft_strlen(outputfile) > 0)
		o = 0;
	if (i < 0 || o < 0)
		return (-1);
	return (0);
}

void	free_matrix(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	**ft_get_environment(char **envp)
{
	int	i;

	if (*envp == NULL)
		return (ft_set_global_path());
	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (envp[i] == NULL)
		return (envp);
	return (ft_split(envp[i] + 5, ':'));
}

char	*ft_get_path(char **envp, char *cmnd)
{
	int		i;
	char	*path;

	i = 0;
	if (!cmnd)
		return (NULL);
	if (ft_strrchr(cmnd, '/'))
		return (cmnd);
	while (envp[i])
	{
		path = ft_strjoin(ft_strjoin(envp[i], "/"), cmnd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	ft_err_msg(int error, char **path)
{
	ft_putstr_fd(strerror(error), 2);
	if (path)
		free_matrix(path);
}
