/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:18:14 by ykoseki           #+#    #+#             */
/*   Updated: 2023/11/11 23:31:51 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_s(char *str)
{
	size_t	a;

	a = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (*(str + a) != '\0')
		a++;
	return (a);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size < 1)
		return (ft_strlen_s((char *)src));
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (ft_strlen_s((char *)src));
}

char	*ft_strnjoin(char *s1, char *s2, int len1, int len2)
{
	char	*tmp;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = len1 + len2 + 1;
	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, (char *)s1, len1 + 1);
	ft_strlcpy(tmp + len1, (char *)s2, len2 + 1);
	return (tmp);
}

size_t	ft_strchr(char *s, int c)
{
	size_t	num;

	num = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		num++;
	}
	return (num);
}

char	*ft_strdup(const char *src)
{
	char	*p;
	long	len;

	len = ft_strlen_s((char *)src);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}
