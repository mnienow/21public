/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:19:15 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/21 20:19:18 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		*ft_range(size_t min, size_t max)
{
	size_t	i;
	size_t	g;
	size_t	*arr;

	g = 0;
	i = max - min;
	if (min < max)
	{
		if (!(arr = malloc(sizeof(int) * i)))
			return (NULL);
		while (min < max)
		{
			arr[g] = min;
			g++;
			min++;
		}
		return (arr);
	}
	else
		return (0);
}
