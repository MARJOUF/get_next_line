/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:57:38 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/13 19:57:54 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
char *ft_join(char *stash, char *buffer);
char *ft_get_read(char *stash, int fd, ssize_t *a);
char *ft_get_one_line(char *stash);
char *ft_free(char *stash);
char *ft_get_new_stash(char *stash);
char *ft_strchr(char *str, char c);
int ft_get_strline(char *str);
char *ft_get_join(char *s1, char *s2);

#endif