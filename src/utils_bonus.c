/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:26:57 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/21 18:28:44 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_first_arg(char *argv[])
{
	int	i;

	i = 0;
	while(ft_strncmp(argv[i], "./pipex", ft_strlen(argv[i])) != 0)
		i++;
	i++;
	/* if (ft_strncmp(argv[i], "here_doc", ft_strlen(argv[i])) == 0)
		i = i + 2; */
	return (i);
}

int	ft_access_rights_bonus(char *inputfile, char *outputfile)
{
	int	x;
	
	x = access(outputfile, W_OK);
	if (x < 0 && errno != 2)
		return (perror("Error\nOutput file\nDescription"), -1);
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

int	delimiter_pos(const char *input, const char *delimiter)
{
	int	i;

	i = 0;
	while (delimiter && ft_strchr(delimiter, (int)input[i]) != 0)
		i++;
	ft_printf("%s\n", input[i]);
	return (i);
}


int	check_for_delimiter(const char *deli, char *input)
{
	int i;
	size_t j;

	i = 0;
	while (input[i] != '\0')
	{
		j = 0;
		while (input[i] == deli[j] && input[i] != '\0' && deli[i] != '\0' && j <= ft_strlen(deli))
		{
			ft_putchar_fd(input[i], 1);
			ft_putchar_fd('-', 1);
			ft_putchar_fd(deli[j], 1);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("ENTER deli", 1);
			ft_putstr_fd(input, 1);
			if ((deli[j + 1] == '\0' && input[i + 1]) == '\0' || (ft_isprint(input[i + 1]) == 0 || input[i + 1] == '\n'))
				return (1);
			i++;
			j++;
		}
		i++;
	}
	return (0);
}

/* void read_input_limiter(int i, char *argv[])
{
	int input;
	char *temp;
	ssize_t bytes_read;

	temp = ft_gnl_calloc((BUFFER_SIZE + 2), sizeof(char));
	input = open(argv[i], O_RDWR, S_IRWXU);
	if (!temp)
		return (NULL);
	while (bytes_read != 0 && !ft_gnl_strchr(temp, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read >= 0)
			temp[bytes_read] = '\0';
		if (bytes_read < 0)
		{
			if (buffer != NULL)
				free(buffer);
			return (free(temp), NULL);
		}
		buffer = ft_gnl_strjoin(buffer, temp);
	}

	bytes_read = 1;
	
		ft_putstr_fd(temp, input);

} */
void read_input_limiter(int i, char *argv[])
{
	int input;
	char *temp;
	ssize_t bytes_read;

	temp = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	//ft_putstr_fd(argv[i], 1);
	input = open(argv[i], O_RDWR, S_IRWXU);
	bytes_read = 1;
	// DO A GNL INSTEAD TO GET FULL LINE THEN DO DELIMITER CHECK
	while (bytes_read != 0)
	{
		bytes_read = read(1, temp, BUFFER_SIZE);
		//ft_putstr_fd(argv[i + 1], 1);
		if (bytes_read < 0)
			break ;
		if (check_for_delimiter(argv[i + 1], temp) == 1)
		{
			ft_putstr_fd("ENTER", 1);
			bytes_read = delimiter_pos(temp, argv[i + 1]);
			while (bytes_read-- > 0)
			{
				write(input, &temp, 1);
				temp++;
			}
			break ;
		} 
		ft_putstr_fd(temp, input);
		//write(input, &temp, BUFFER_SIZE);
	} 
	ft_putstr_fd("EXIT", 1);
	free (temp);
	close(input);
}
 
