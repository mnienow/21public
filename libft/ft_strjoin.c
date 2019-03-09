/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:28:23 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/06 13:28:25 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str = ft_strcpy(str, (char *)s1);
		str = ft_strcat(str, (char *)s2);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
