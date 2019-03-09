/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:16:29 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/29 14:41:21 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
	while (g < i)
	{
		arr[g] = s1[g];
		g++;
	}
	arr[i] = '\0';
	return (arr);
}
