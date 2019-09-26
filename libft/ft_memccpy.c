/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:44:36 by mnienow           #+#    #+#             */
/*   Updated: 2018/11/25 21:31:51 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char *ss;

	ss = (unsigned char *)s;
	while (n--)
	{
		*((unsigned char*)d++) = *ss;
		if (*ss++ == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
