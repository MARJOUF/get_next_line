/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:53:11 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/15 15:32:27 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stash)
{
	free(stash);
	stash = NULL;
	return (NULL);
}

char	*ft_join(char *stash, char *buffer)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_get_join(stash, buffer);
	free(stash);
	free(buffer);
	return (tmp);
}

char	*ft_get_read(char *stash, int fd, ssize_t *a)
{
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(stash));
	*a = read(fd, buffer, BUFFER_SIZE);
	if (*a == -1)
	{
		free(buffer);
		return (ft_free(stash));
	}
	if (*a > 0)
	{
		buffer[*a] = '\0';
		stash = ft_join(stash, buffer);
		if (!stash)
			*a = -1;
	}
	if (*a == 0)
		free(buffer);
	return (stash);
}

char	*ft_get_one_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (ft_free(stash));
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (j == 0)
		return (ft_free(stash));
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		a;

	a = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (a > 0)
	{
		if (ft_strchr(stash, '\n'))
			break ;
		stash = ft_get_read(stash, fd, &a);
		if (!stash)
			return (ft_free(stash));
		if (ft_strchr(stash, '\n'))
			break ;
	}
	line = ft_get_one_line(stash);
	if (!line)
		return (ft_free(stash));
	stash = ft_get_new_stash(stash);
	return (line);
}
