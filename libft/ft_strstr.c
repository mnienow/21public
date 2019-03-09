/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:06:27 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/02 00:06:29 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (*(char *)needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack)
	{
		if (*haystack == needle[i])
			i++;
		else
		{
			haystack = haystack - i;
			i = 0;
		}
		if (needle[i] == '\0')
			return ((char *)(haystack - i + 1));
		haystack++;
	}
	return (NULL);
}
