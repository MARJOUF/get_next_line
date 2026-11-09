/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:47:30 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/09 22:08:13 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_overwrite(char *stash)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\0')
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    i++;
    while(stash[i])
        stash[j++] = stash[i++];
    if (j == 0)
    {
        free(stash);
        return (NULL);
    }
    stash[j] = '\0';
    return (stash);
}

int ft_strchr(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if(str[i] == '\n')
        {
            return (1);
        }
        i++;
    }
    return 0;
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char *ft_join(char *s1, char *s2)
{
    char *new_str;
    int i;
    int a;
    int len;

    i = 0;
    a = 0;
    len = ft_strlen(s1);
    new_str = malloc(len + ft_strlen(s2) + 1);
    if (new_str == NULL)
        return (NULL);
    while (i < len)
    {
        new_str[a] = s1[i];
        a++;
        i++;
    }
    i = 0;
    while (s2[i])
    {
        new_str[a] = s2[i];
        a++;
        i++;
    }
    new_str[a] = '\0';
    free(s1);
    return (new_str);
}
