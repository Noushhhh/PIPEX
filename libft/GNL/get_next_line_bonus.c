/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:39:51 by aandric           #+#    #+#             */
/*   Updated: 2022/04/27 14:08:44 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_save_rest(char *buffer, char *shifted_buffer)
{
	int	i;

	i = 0;
	while (*shifted_buffer)
	{
		buffer[i] = *shifted_buffer;
		shifted_buffer++;
		i++;
	}
	buffer[i] = '\0';
}

char	*get_line(char *line, char *buffer, int fd)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		if (ft_chrn(buffer) != -1)
		{
			ft_save_rest(buffer, &buffer[ft_chrn(buffer) + 1]);
			return (line);
		}	
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[ret] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = get_line(line, buffer[fd], fd);
	if (ft_strlen_gnl(line))
		return (line);
	free(line);
	return (NULL);
}

/*
#include <stdio.h>
int main ()
{
	int	fd;
	int fd2;

	fd = open("file", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	//printf("fd = %d", fd);
	
	char *res = get_next_line(fd);
	while (res)
	{
		printf("res: '%s'", res);
		res = get_next_line (fd);
	}
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	
	
	close(fd);
}
*/
