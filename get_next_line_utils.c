/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:12 by pnielly           #+#    #+#             */
/*   Updated: 2019/11/13 11:27:04 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char		*dst;
	long		len;
	const char	*src1;
	char		*d1;

	len = ft_strlen(s1) + 1;
	if (!(dst = (char *)malloc(sizeof(char) * len)))
		return ((char *)0);
	if (!s1 && !dst)
		return (0);
	src1 = s1;
	d1 = dst;
	if (!len)
		return (dst);
	while (len-- > 0)
		*d1++ = *src1++;
	return (dst);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] != needle[0] && haystack[i] != '\0' && i < len)
			i++;
		while (haystack[i] == needle[j] && j < len && i < len && needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' || j == len)
		{
			haystack = &haystack[i - j];
			return ((char *)haystack);
		}
	}
	return (NULL);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	long	i;
	long	j;
	long	k;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = malloc(sizeof(char) * (i + j) + 1)))
		return (0);
	while (++k < i)
		str[k] = s1[k];
	while (k < i + j)
	{
		str[k] = s2[k - i];
		k++;
	}
	str[k] = '\0';
	return (str);
}
