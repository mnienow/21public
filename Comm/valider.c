/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 14:11:07 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		err(int n)
{
	if (!n)
		write(2, "Error\n", 6);
	else if (n == 1)
		write(2, "Method error(1)\n", 16);
	else
		write(2, "Method error(2)\n", 16);
	exit(n);
}

void		check_input_dups(char **str)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = -1;
	while (str[++i])
	{
		if (!ft_isnumber(str[i]))
			err(0);
		string = str[i];
		j = i;
		while (str[++j])
			if (!ft_strcmp(str[j], string))
				err(0);
	}
}

long		*get_longs(char **str, size_t len)
{
	size_t	i;
	long	*longs;

	i = -1;
	longs = (long*)malloc(sizeof(long) * len);
	while (++i < len)
		longs[i] = ft_atol(str[i]);
	i = 0;
	while (len--)
	{
		if (longs[len] > 2147483647 || longs[len] < -2147483648)
			err(0);
		if (longs[len] == 0)
			i++;
	}
	if (i > 1)
		err(0);
	return (longs);
}

t_lst		*valider(char **str, size_t *len)
{
	long	*longs;
	char	**args;
	int		i;
	t_lst	*a;

	i = 0;
	if (*len < 2)
	{
		args = ft_strsplit(str[0], 32);
		*len = ft_arrlen((void**)args);
	}
	else
		args = str;
	check_input_dups(args);
	longs = get_longs(args, *len);
	a = set_stack_a(longs, *len);
	if (args != str)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
	free(longs);
	return (a);
}
