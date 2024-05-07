/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:31:10 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 19:53:50 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int	is_here(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*_fill_buffer(int fd, char **buffer)
{
	char		tmp[BUFFER_SIZE + 1];
	ssize_t		byte_read;

	byte_read = 1;
	while (is_here(*buffer, '\n') == -1 && byte_read > 0)
	{
		byte_read = read (fd, tmp, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(*buffer);
			*buffer = NULL;
			break ;
		}
		if (byte_read == 0)
			break ;
		tmp[byte_read] = '\0';
		*buffer = ft_strjoin1(*buffer, tmp);
	}
	return (*buffer);
}

void	set_lines(char **buffer, char **str)
{
	char	*s;

	*str = ft_substr1(*buffer, 0, is_here(*buffer, '\n') + 1);
	if (*str == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	s = *buffer;
	*buffer = ft_strdup1(*buffer + (is_here(*buffer, '\n') + 1));
	if (s)
		free(s);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = _fill_buffer(fd, &buffer);
	if (is_here(buffer, '\n') == -1)
	{
		if (buffer == NULL || *buffer == '\0')
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		str = buffer;
		buffer = NULL;
		return (str);
	}
	set_lines(&buffer, &str);
	return (str);
}
