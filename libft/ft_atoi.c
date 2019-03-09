/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 01:40:48 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/02 01:40:51 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	size_t				i;

	result = 0;
	sign = 0;
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] != '+');
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (result != result * 10 / 10)
			return (sign == 1 ? 0 : -1);
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (sign == 1)
		result = result * -1;
	return (result);
}
