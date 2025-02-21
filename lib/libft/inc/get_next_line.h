/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:53:46 by aehrl             #+#    #+#             */
/*   Updated: 2025/02/19 19:02:34 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Start file
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 8
# endif

//Include Libraries
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *buffer);
char	*ft_update_bufffer(char *buffer);
char	*ft_gnl_strchr(const char *s, int c);
size_t	ft_gnl_strlen(const char *str);

#endif
