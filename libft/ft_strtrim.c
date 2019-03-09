/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:57:58 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/06 15:58:00 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*arr;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
		if (s[start] == '\0')
			return (ft_strdup(s + start));
		if (!(arr = ft_strnew(end - start)))
			return (NULL);
		arr = ft_strncpy(arr, s + start, end - start);
		return (arr);
	}
	return (NULL);
}
