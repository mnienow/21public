/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:14:45 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/01 23:14:47 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen((char *)s) + 1;
	while (*(char *)s)
		s++;
	while (i--)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
