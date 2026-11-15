/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akmarjou <akmarjou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:47:18 by akmarjou          #+#    #+#             */
/*   Updated: 2026/11/15 15:59:55 by akmarjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_join(char *stash, char *buffer);
char	*ft_get_read(char *stash, int fd, ssize_t *a);
char	*ft_get_one_line(char *stash);
char	*ft_free(char *stash);
char	*ft_get_new_stash(char *stash);
char	*ft_strchr(char *str, char c);
int		ft_get_strline(char *str);
char	*ft_get_join(char *s1, char *s2);

#endif
