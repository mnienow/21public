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

	i = -1;
	while (str[++i])
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
    size_t  i;
	long	*longs;
	int		count0;

	i = -1;
	longs = (long*)malloc(sizeof(long) * len);
	while (++i < len)
		longs[i] = ft_atol(str[i]);
	i = 0;
    while (len--)
    {
        if (longs[len] > 2147483647 || longs[len] < -2147483648)
            err();
        if (longs[len] == 0)
            i++;
    }
    if (i > 1)
        err();
	return (longs);
}

t_lst 		*valider(char **str, size_t len)
{
	long	*longs;
	char	**args;
    t_lst   *a;

	if (len < 2)
	{
		args = ft_strsplit(str[0], 32);
		len = ft_arrlen((void**)args);
		str = args;
	}
	check_input_dups(str);
	longs = get_longs(str, len);
	a = set_stack_a(longs, len);
	free(longs);
	return (a);
}