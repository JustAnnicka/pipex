/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:26:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/25 18:35:36 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_first_arg(char *argv[])
{
	int	i;

	i = 0;
	while (ft_strncmp(argv[i], "./pipex", ft_strlen(argv[i])) != 0)
		i++;
	i++;
	return (i);
}

int	ft_access_rights_bonus(char *inputfile, char *outputfile)
{
	int	x;

	x = access(outputfile, W_OK);
	if (x < 0 && errno != 2)
		return (perror("Error\nOutput file\nDescription"), -1);
	else if (x < 0 && errno == 2)
		x = 0;
	if (ft_strncmp(inputfile, "here_doc", ft_strlen(inputfile) != 0))
	{
		x = access(inputfile, R_OK);
		if (x < 0)
			return (perror("Error\nInput file\nDescription"), -1);
	}
	else
		open(inputfile, O_RDWR | O_CREAT, S_IRWXU);
	return (x);
}

void	read_input_limiter(int i, char *argv[])
{
	char	*input;
	int		delimiter;
	int		fd;

	delimiter = 1;
	fd = open(argv[i], O_RDWR, S_IRWXU);
	while (delimiter == 1)
	{
		input = get_next_line(1);
		if (ft_strlen(input) - 1 != ft_strlen(argv[i + 1]))
			ft_putstr_fd(input, fd);
		else if (ft_strncmp(input, argv[i + 1], ft_strlen(argv[i + 1])) != 0)
		{
			ft_putstr_fd(input, fd);
		}
		else
			break ;
	}
	free(input);
	close(fd);
}

void	del_heredoc(char *argv[])
{
	int	i;

	i = get_first_arg(argv);
	if (ft_strncmp(argv[i], "here_doc", ft_strlen(argv[i])) == 0)
		unlink(argv[i]);
}
