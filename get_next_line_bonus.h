/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:42:17 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/24 02:37:05 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# if !BUFFER_SIZE || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX + 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*ft_strnjoin(char *s1, char *s2, int len1, int len2);
size_t	ft_strchr(char *s, int c);
size_t	ft_strlen_s(char *str);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
char	*get_newline(int fd, char *line, char **rest);
int		ft_concat_line(char **line, char *buf, char **rest);
char	*all_free(char *line, char *buf);

#endif
