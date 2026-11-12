/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:47:18 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/12 15:13:52 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char *get_next_line(int fd);
char *ft_get_line(char *str, char n);
char *ft_str_join(char *s1, char *s2);
char *ft_new_stash(char *stash);
char *ft_free(char *stash, char *buffer);

#endif