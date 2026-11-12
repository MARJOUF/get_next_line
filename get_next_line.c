 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:46:48 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/11 17:30:06 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join(char *stash, char *buffer)
{
    char *tmp;

    tmp = NULL;
    tmp = ft_str_join(stash, buffer);
    free(buffer);
    free(stash);
    return (tmp);
}

static char *ft_read(char *stash, int fd, ssize_t *a)
{
    char *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
        *a = -1;
        free(stash);
        return (NULL);
    }
    *a = read(fd, buffer, BUFFER_SIZE);
    if (*a == -1)
        return (ft_free(stash, buffer));
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

static char *ft_stash(char *stash, int fd)
{
    ssize_t a;

    a = 1;
    if (ft_get_line(stash, '\n'))
        return (stash);
    while (a > 0)
    {
        stash = ft_read(stash, fd, &a);
        if (ft_get_line(stash, '\n'))
            break;
    }
    return (stash);
}

static char *ft_line(char *stash)
{
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!stash || stash[0] == '\0')
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    while (j < i)
    {
        line[j] = stash[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = ft_stash(stash, fd);
    if (!stash)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    line = ft_line(stash);
    if (!line)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = ft_new_stash(stash);
    return (line);
}
