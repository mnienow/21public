/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:31:00 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/18 20:20:58 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	wtfstrings(const int fd, char **line, char **mbuf, int ret)
{
	if (mbuf[fd][0] && !ret)
	{
		CHN(*line = ft_strdup(mbuf[fd]));
		free(mbuf[fd]);
		mbuf[fd] = NULL;
		return (1);
	}
	return (0);
}

int	nextbuf(const int fd, char **line, char **mbuf)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (mbuf[fd][i])
	{
		if (mbuf[fd][i] == '\n')
		{
			mbuf[fd][i] = '\0';
			CHN(*line = ft_strdup(mbuf[fd]));
			tmp = mbuf[fd];
			CHN(mbuf[fd] = ft_strdup(&mbuf[fd][++i]));
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	readnext(const int fd, char **line, char **mbuf, char *tmp)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		CHN(ret > 0);
		buf[ret] = '\0';
		if (!ft_strchr(buf, '\n'))
		{
			tmp = mbuf[fd];
			CHN(mbuf[fd] = ft_strjoin(mbuf[fd], buf));
			free(tmp);
		}
		else
		{
			ft_strchr(buf, '\n')[0] = '\0';
			CHN(*line = ft_strjoin(mbuf[fd], buf));
			free(mbuf[fd]);
			CHN(mbuf[fd] = ft_strdup((char*)buf + ft_strlen(buf) + 1));
			return (1);
		}
	}
	R(wtfstrings(fd, line, mbuf, ret));
}

int	get_next_line(const int fd, char **line)
{
	static char	**mbuf;
	char		*tmp;

	tmp = NULL;
	CH(!line || fd < 0 || fd > 10400);
	if (!mbuf)
		CHN(mbuf = (char**)malloc(sizeof(char*) * 10400));
	if (!mbuf[fd])
		CHN(mbuf[fd] = ft_strnew(0));
	if (nextbuf(fd, line, mbuf) > 0 ||
			readnext(fd, line, mbuf, tmp) > 0)
		return (1);
	if (nextbuf(fd, line, mbuf) < 0 || readnext(fd, line, mbuf, tmp) < 0)
		return (-1);
	CHN(*line = ft_strnew(0));
	return (0);
}
