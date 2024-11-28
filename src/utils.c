/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:05 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/28 16:26:39 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **ft_get_environment(char **envp)
{
	int		i;
	//char 	*p;
	char	**newenvp;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	return(ft_split(envp[i] + 5, ':'));
/* 	newenvp = ft_split(envp[i], ':');
	i = 0; */
/* 	while (newenvp[i] != NULL && newenvp[i] != 0)
	{
		ft_printf("cmnd[%d]: %s\n", i, newenvp[i]);
		i++;
	} */
	//FREE ENVP
	return (newenvp);
}
char *ft_get_path(char **envp, char *cmnd)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strjoin(ft_strjoin(envp[i], "/"), cmnd);
	
		if (access(path, X_OK) == 0)
			return (ft_printf("found:%s\n", path), path);
		free(path);
		i++;
	}
	ft_printf("NOT FOUND\n");
	return (NULL);
}
