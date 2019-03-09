/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:53:24 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/21 19:53:25 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	g;
	char	*arr;

	i = 0;
	g = 0;
	while (s1[i] != '\0')
		i++;
	if (!(arr = malloc(sizeof(*s1) * (i + 1))))
		return (NULL);
	while (g < i && n > 0)
	{
		arr[g] = s1[g];
		g++;
		n--;
	}
	arr[i] = '\0';
	return (arr);
}
