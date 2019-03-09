/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:13:39 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/07 15:13:41 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c)
	{
		str++;
	}
	while (*str)
	{
		while (*str != c && *str != '\0')
		{
			str++;
		}
		while (*str == c)
		{
			str++;
		}
		count++;
	}
	return (count);
}
