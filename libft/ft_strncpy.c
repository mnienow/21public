/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:05:42 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/29 21:05:44 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	ln;
	size_t	i;
	size_t	temp;

	i = 0;
	ln = ft_strlen(src);
	temp = len;
	if (len > ln)
		len = ln;
	while (len--)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < temp)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
