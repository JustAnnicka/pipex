/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:26:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/03/19 16:37:53 by aehrl            ###   ########.fr       */
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
	int	i;
	int	o;

	if (ft_strncmp(inputfile, "here_doc", ft_strlen(inputfile) != 0))
	{
		i = access(inputfile, R_OK);
		if (i < 0)
			ft_err_msg(errno, NULL);
	}
	else
		open(inputfile, O_RDWR | O_CREAT, S_IRWXU);
	o = access(outputfile, W_OK);
	if (o < 0 && (errno != 2 || ft_strlen(outputfile) == 0))
		ft_err_msg(errno, NULL);
	else if (errno == 2 && ft_strlen(outputfile) > 0)
		o = 0;
	if (i < 0 || o < 0)
		return (-1);
	return (0);
}

void	read_input_limiter(int i, char *argv[])
{
	char	*input;
	int		fd;

	fd = open(argv[i], O_RDWR, S_IRWXU);
	while (1)
	{
		write(1, "here_doc> ", 10);
		input = get_next_line(0);
		if (input && ft_strlen(input) - 1 != ft_strlen(argv[i + 1]))
			ft_putstr_fd(input, fd);
		else if (input
			&& ft_strncmp(input, argv[i + 1], ft_strlen(argv[i + 1])) != 0)
			ft_putstr_fd(input, fd);
		else
			break ;
		free(input);
	}
	if (!input)
	{
		unlink("here_doc");
		exit(2);
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
