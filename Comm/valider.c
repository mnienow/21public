/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/28 21:49:37 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		err(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void		check_input_dups(char **str)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
			err();
		string = str[i];
		j = i;
		while (str[++j])
			if (!ft_strcmp(str[j], string))
				err();
		i++;
	}
}

long		*get_longs(char **str, size_t len)
{
	long	*longs;
	int		count0;

	count0 = 0;
	longs = (long*)malloc(sizeof(long) * len);
	while (len)
	{
		longs[len - 1] = ft_atol(str[len - 1]);
		if (longs[len - 1] == 0)
			count0++;
		len--;
	}
	if (count0 > 1)
		err();
	return (longs);
}

void		check_longs(long *longs, size_t len)
{
	while (len--)
		if (longs[len] > 2147483647 || longs[len] < -2147483648)
			err();
}

t_lst 		*valider(char **str, size_t len)
{
	long	*longs;

	check_input_dups(str);
	longs = get_longs(str, len);
	check_longs(longs, len);
	return (set_stack_a(longs, len));
}