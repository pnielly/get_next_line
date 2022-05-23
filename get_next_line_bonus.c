/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:55:00 by pnielly           #+#    #+#             */
/*   Updated: 2019/11/13 11:55:02 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	unsigned	i;
	unsigned	j;

	if (!s)
		return (NULL);
	if (!(dest = malloc(len + 1)))
		return (0);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	j = start;
	while (len-- > 0 && s[j] != 0)
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list			*get_correct_stock(int fd, t_list **check)
{
	t_list	*tmp;

	tmp = *check;
	while (tmp)
	{
		if (tmp->file == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->file = fd;
	tmp->content = ft_strdup("");
	tmp->next = *check;
	*check = tmp;
	return (tmp);
}

int				endfile_or_error(char *curr, char **line, int fd, t_list *stock)
{
	char		buf[BUFFER_SIZE + 1];

	stock->content = ft_strdup("");
	free(stock->content);
	stock->content = NULL;
	if (read(fd, buf, BUFFER_SIZE) == 0)
	{
		if (curr)
		{
			*line = ft_strdup(curr);
			free(curr);
		}
		else
			*line = ft_strdup("");
		return (0);
	}
	return (-1);
}

char			*get_curr(t_list *stock, int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 1;
	while (!(ft_strnstr(stock->content, "\n",
					ft_strlen(stock->content))) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1 || fd < 0)
			return (NULL);
		if (!ret)
			break ;
		buf[ret] = '\0';
		tmp = ft_strjoin(stock->content, buf);
		free(stock->content);
		stock->content = tmp;
	}
	return (stock->content);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*check;
	char			*curr;
	int				i;
	t_list			*stock;

	stock = get_correct_stock(fd, &check);
	if (!(ft_strnstr(stock->content, "\n", ft_strlen(stock->content))))
	{
		curr = get_curr(stock, fd);
		if (!curr || !ft_strnstr(curr, "\n", ft_strlen(curr)))
			return (endfile_or_error(curr, line, fd, stock));
	}
	else
		curr = stock->content;
	i = 0;
	while (curr[i] != '\n' && curr[i])
		i++;
	stock->content = ft_substr(curr, i + 1, ft_strlen(curr) - i + 1);
	curr[i] = '\0';
	*line = ft_strdup(curr);
	free(curr);
	return (1);
}
