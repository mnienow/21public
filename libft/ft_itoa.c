/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:15:00 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/06 17:15:01 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftcount(int n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	l;
	char	*str;

	l = 0;
	i = ftcount(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		l = 1;
		n = -n;
	}
	str[i] = '\0';
	while (i > l)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
