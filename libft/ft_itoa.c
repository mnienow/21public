/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:16:19 by mnienow           #+#    #+#             */
/*   Updated: 2018/12/12 19:53:05 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*res;
	int		count;
	long	nb;

	count = n < 0 ? 2 : 1;
	nb = n < 0 ? -(long)n : (long)n;
	while (nb /= 10)
		count++;
	nb = n < 0 ? -(long)n : (long)n;
	if (!(res = (char *)malloc(count + 1)))
		return (0);
	res[count] = 0;
	while (--count > -1)
	{
		res[count] = (nb % 10) + 48;
		nb /= 10;
	}
	n < 0 ? res[0] = '-' : 0;
	return (res);
}
