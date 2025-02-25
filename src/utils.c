/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:05 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/25 18:33:24 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	free_matrix(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	**ft_get_environment(char **envp)
{
	int		i;
	char	**newenvp;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
	return (newenvp);
}

char	*ft_get_path(char **envp, char *cmnd)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strjoin(ft_strjoin(envp[i], "/"), cmnd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_putstr_fd("Error path not found\n", 1);
	return (NULL);
}
