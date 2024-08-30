/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:18:11 by ykoseki           #+#    #+#             */
/*   Updated: 2024/08/30 15:01:15 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*all_free(char *line, char *buf)
{
	free(line);
	free(buf);
	return (NULL);
}

int	vsnorm(char **line, char **rest)
{
	free(*rest);
	*rest = NULL;
	*line = NULL;
	return (1);
}

int	ft_concat_line(char **line, char *buf, char **rest)
{
	int		flag;
	char	*tmp;
	size_t	rest_len;

	flag = 0;
	rest_len = ft_strchr(buf, '\n');
	tmp = ft_strnjoin(*line, buf, ft_strlen_s(*line), rest_len + 1);
	free(*line);
	if (!tmp)
		return (vsnorm(line, rest));
	*line = tmp;
	if (buf[rest_len] == '\n')
	{
		flag = 1;
		tmp = ft_strdup(buf + rest_len + 1);
		if (!tmp)
			return (vsnorm(line, line));
	}
	free(*rest);
	*rest = tmp;
	return (flag);
}

char	*get_newline(int fd, char *line, char **rest)
{
	char	*buf;
	ssize_t	read_bytes;
	int		flag;

	flag = 0;
	buf = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		free(line);
		return (NULL);
	}
	read_bytes = BUFFER_SIZE;
	while (!flag && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (all_free(line, buf));
		buf[read_bytes] = '\0';
		flag = ft_concat_line(&line, buf, rest);
	}
	if ((!ft_strlen_s(line) && !read_bytes) || read_bytes == -1)
		return (all_free(line, buf));
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	int			find_flag;

	find_flag = 0;
	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
	{
		if (rest[fd])
		{
			free(rest[fd]);
			rest[fd] = NULL;
		}
		return (NULL);
	}
	*line = '\0';
	if (rest[fd])
		find_flag = ft_concat_line(&line, rest[fd], &rest[fd]);
	if (find_flag == 1)
		return (line);
	return (get_newline(fd, line, &rest[fd]));
}

int main(){
	char *str;

	int fd = open("get_next_line.c", O_RDONLY);

	for (int i = 0; i < 5; i++)
	{
		str = get_next_line(fd);

		printf("%d: %s",i,str);
		free(str);
	}
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }
// __attribute__((destructor))