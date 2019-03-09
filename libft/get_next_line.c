/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:37:49 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/26 20:40:53 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_end_line(int i, char *buf, char **line, t_list **tmp)
{
	char			*buffer;
	char			*save;

	buffer = ft_strsub(buf, 0, i);
	save = (*tmp)->content;
	((*tmp)->content) = ft_strjoin((*tmp)->content, buffer);
	free(save);
	free(buffer);
	*line = ft_strdup((*tmp)->content);
	free((*tmp)->content);
	buffer = ft_strsub(buf, i + 1, (ft_strlen(buf) - (i + 1)));
	(*tmp)->content = ft_strdup(buffer);
	free(buffer);
	return (1);
}

static int			ft_check_buf(t_list **tmp, char **line)
{
	char			*buf;
	int				i;

	i = 0;
	buf = ft_strdup((*tmp)->content);
	free((*tmp)->content);
	(*tmp)->content = NULL;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*line = ft_strsub(buf, 0, i);
			(*tmp)->content = ft_strsub(buf, i + 1, (ft_strlen(buf) - (i + 1)));
			free(buf);
			return (1);
		}
		i++;
	}
	(*tmp)->content = ft_strdup(buf);
	free(buf);
	return (0);
}

static int			ft_last_string(char **line, t_list **tmp)
{
	*line = ft_strdup((*tmp)->content);
	free((*tmp)->content);
	(*tmp)->content = NULL;
	return (1);
}

static	int			ft_get_read(int fd, char *buf, char **line, t_list **tmp)
{
	int				i;

	i = 0;
	if ((*tmp)->content && ((i = ft_check_buf(tmp, line) == 1 || i == -1)))
		return (i);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		CHECK(i);
		buf[i] = '\0';
		i = -1;
		while (buf[++i] != '\0')
		{
			if (buf[i] == '\n')
				return (ft_end_line(i, buf, line, tmp));
		}
		*line = (*tmp)->content;
		if (!((*tmp)->content = ft_strjoin((*tmp)->content, buf)))
			return (-1);
		free(*line);
	}
	if ((*tmp)->content && !(ft_strcmp((*tmp)->content, "") == 0))
		return (ft_last_string(line, tmp));
	*line = ft_strnew(0);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	int				out;
	char			*buf;

	if (fd < 0 || !(line))
		return (-1);
	CHECKMALL(buf = (char *)(malloc(sizeof(char) * (BUFF_SIZE + 1))));
	tmp = list;
	while (list)
	{
		if ((int)list->content_size == fd)
			break ;
		list = list->next;
	}
	if (list == NULL)
	{
		list = ft_lstnew("\0", 1);
		list->content_size = fd;
		ft_lstadd(&tmp, list);
	}
	out = ft_get_read(fd, buf, line, &list);
	list = tmp;
	free(buf);
	return (out);
}
