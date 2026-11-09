/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:46:48 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/09 22:26:15 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_append(char *stash, char *buffer)
{
    char *temp;

    temp = NULL;
    temp = ft_join(stash, buffer);
    if (!temp)
    {
        free(stash);
        free(buffer);
        return (NULL);
    }
    free(buffer);
    return (temp);
}

static char *ft_read(int fd, char *stash, ssize_t *a)
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
    {
        free(buffer);
        free(stash);
        return (NULL);
    }  
    if (*a > 0)
    {
        buffer[*a] = '\0';
        stash = ft_append(stash, buffer);
        if (!stash)
            *a = -1;
    }
    if (*a == 0)
        free(buffer);
    return (stash);
}

static char *ft_line(int fd, char *stash)
{
    ssize_t a;
    int j;

    a = 1;
    j = 0;
    if (ft_strchr(stash))
        return (stash);
    while (a > 0)
    {
        stash = ft_read(fd, stash, &a);
        j = ft_strchr(stash);
        if (j == 1)
            break ;
    }
    return (stash);
}

static char *ft_extract_line(char *stash)
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
    stash = ft_line(fd, stash);
    if (!stash)
    {
        free(stash);
        stash = NULL; 
        return (NULL);
    }
    line = ft_extract_line(stash);
    if (!line)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = ft_overwrite(stash);
    return (line);
}
