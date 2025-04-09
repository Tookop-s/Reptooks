/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:24:43 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 13:26:04 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr2(char *s, int c)
{
	unsigned int	i;
	char			search;

	if (!s)
		return (NULL);
	search = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == search)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == search)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*buffer_line_copy(char *buffer_line)
{
	char	*line;

	if (ft_strlen(buffer_line) != 0)
	{
		line = ft_strdup(buffer_line);
		if (!line)
			return (NULL);
		buffer_line[0] = '\0';
	}
	else
		line = NULL;
	return (line);
}

static char	*fill_line(int fd, char *buffer_line, char *buffer, char *line)
{
	int		index_read;

	index_read = 1;
	line = buffer_line_copy(buffer_line);
	while (!ft_strchr2(line, '\n'))
	{
		index_read = read(fd, buffer, BUFFER_SIZE);
		if (index_read == -1)
			return (free(line), NULL);
		else if (index_read == 0)
			return (line);
		buffer[index_read] = '\0';
		if (!line)
		{
			line = ft_strdup("");
			if (!line)
				return (NULL);
		}
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

void	copy_next_line(char *line, char *next_line_buf)
{
	int	i;
	int	max;
	int	j;

	j = 0;
	max = ft_strlen(line);
	i = 0;
	while (i < max && line[i] != '\n')
		i++;
	if (line[i])
		i++;
	while (line[i])
	{
		next_line_buf[j] = line[i];
		i++;
		j++;
	}
	next_line_buf[j] = '\0';
}

char	*ft_get_next_line(int fd)
{
	static char	next_line_buf[BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	line = NULL;
	buffer = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, next_line_buf, buffer, line);
	free(buffer);
	if (!line)
		return (NULL);
	copy_next_line(line, next_line_buf);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	temp = ft_substr(line, 0, i + 1);
	if (!temp)
		return (free(line), NULL);
	return (free(line), temp);
}
