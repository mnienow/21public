/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 15:48:58 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		check_input_dups(char **str)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	while (str[++i])
	{
		if (!ft_isnumber(str[i]))
			err();
		string = str[i];
		j = i;
		while (str[++j])
		{
			if (str[j] == string)
				err();
		}
	}
}

long		*get_longs(char **str)
{
	long	*longs;
	size_t	i;

	i = 0;
	longs = (long*)malloc(sizeof(long) * ft_arrlen(str));
	while (str[++i])
	{
		longs[i - 1] = ft_atol(str[i]);
	}
	return (longs);
}

void		check_longs(long *longs)
{
	size_t	i;

	i = 0;
	while (longs[i])
	{
		if (longs[i] > 2147483647 || longs[i] < -2147483648)
			err();
		i++;
	}
}

long 		*valider(char **str)
{
	long	*longs;

	(void)str;
	check_input_dups(str);
	longs = get_longs(str);
	check_longs(longs);
	return (longs);
}