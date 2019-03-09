/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:45:12 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/30 14:45:16 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst || src)
	{
		i = len;
		if (src <= dst)
		{
			while (len--)
			{
				*((unsigned char *)dst + len) = *((unsigned char *)src + len);
			}
			return (dst);
		}
		else
		{
			while (i--)
			{
				*(unsigned char *)dst++ = *(unsigned char *)src++;
			}
			return (dst - len);
		}
	}
	return (NULL);
}
