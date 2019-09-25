/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:47:45 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/03 21:47:50 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	err(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	pushIt(t_lst **a, t_lst **b, int len)
{
	(void)a;
	(void)b;
	(void)len;
}

int			main(int argc, char **argv)
{
	long	*longs;
	int		i;

	i = 0;
	if (argc > 1)
	{
		longs = valider(&argv[0]);
		i = checker(longs, 0, 0);
		if (i)
			write(1, "KO\n", 4);
		else
			write(1, "OK\n", 4);
	}
	return (0);
}
