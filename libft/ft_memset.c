/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:47:42 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/29 12:47:45 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	set;
	size_t			i;

	i = len;
	set = c;
	while (len > 0)
	{
		*((unsigned char *)b) = set;
		b++;
		len--;
	}
	return (b - i);
}
