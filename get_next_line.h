/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:21:26 by pnielly           #+#    #+#             */
/*   Updated: 2019/11/09 10:05:33 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int					get_next_line(int fd, char **line);

char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned long start, size_t len);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
