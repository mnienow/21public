/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:24:42 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/30 11:24:44 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*alpha;
	unsigned char		*omega;
	size_t				len;

	if (src || dst)
	{
		len = 0;
		alpha = (unsigned char *)dst;
		omega = (unsigned char *)src;
		while (len < n)
		{
			alpha[len] = omega[len];
			len++;
		}
		return (alpha);
	}
	return (NULL);
}
