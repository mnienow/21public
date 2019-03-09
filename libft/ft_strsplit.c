/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:03:51 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/07 16:03:53 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		chrcount(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static	int		spscount(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

static	char	**strfree(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr[0]);
	free(arr);
	arr = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		word_count;
	size_t		word_len;
	size_t		sps;
	size_t		i;

	word_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_wordcount((char *)s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	while (i < word_count)
	{
		word_len = chrcount(s, c);
		sps = spscount(s, c);
		if (!(str[i] = ft_memalloc(word_len + 1)))
			return (strfree(str, i));
		ft_strncpy(str[i], s + sps, word_len);
		s = s + (word_len + sps);
		i++;
	}
	str[i] = NULL;
	return (str);
}
