/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:47:30 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/13 16:31:47 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_new_stash(char *stash)
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

char *ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i])
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return (NULL);
}

int ft_get_strline(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
    
}

char *ft_get_join(char *s1, char *s2)
{  
    char *arr;
    int len_s1;
    int len_s2;
    int i;
    int j;

    i = 0;
    j = 0;
    len_s1 = ft_get_strline(s1);
    len_s2 = ft_get_strline(s2);
    arr = malloc((len_s1 + len_s2) + 1);
    if (!arr)
        return (NULL);
    while (i < len_s1)
        arr[i++] = s1[j++];
    j = 0;
    while (s2[j])
        arr[i++] = s2[j++];
    arr[i] = '\0';
    return (arr);
}
