/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:47:30 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/12 15:13:48 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char *stash, char *buffer)
{
    free(stash);
    free(buffer);
    return (NULL);
}

char *ft_new_stash(char *stash)
{
    int j;
    int i;

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
    while (stash[i])
        stash[j++] = stash[i++];
    if (j == 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);        
    }
    stash[j] = '\0';
    return (stash);
}

char *ft_get_line(char *str, char n)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i])
    {
        if (str[i] == n)
            return (&str[i]);
        i++;
    }
    return (NULL);
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

char *ft_str_join(char *s1, char *s2)
{
    char *ar;
    int line_s2;
    int line_s1;
    int i;
    int j;
    
    i = 0;
    j = 0;
    line_s2 = ft_strlen(s2);
    line_s1 = ft_strlen(s1);
    ar = malloc((line_s1 + line_s2) + 1);
    if(!ar)
        return (NULL);
    while (i < line_s1)
        ar[i++] = s1[j++];
    j = 0;
    while (s2[j])
        ar[i++] = s2[j++];
    ar[i] = '\0';
    return (ar);
}