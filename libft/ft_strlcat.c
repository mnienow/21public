/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:41:51 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/30 19:41:54 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len1;
	size_t len2;

	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (len1 < size)
	{
		ft_strncat(dst, src, ((size - 1) - len1));
		return (len2 + len1);
	}
	else
		return (len2 + size);
}
