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

int			main(int argc, char **argv)
{
	long	*longs;
	t_lst	*a;
	t_lst	*b;

	if (argc > 1)
	{
		longs = valider(&argv[0]);
		a = set_stack_a(longs);
		b = 0;
		parser(&a, &b);
		if (finalcheck(a, b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
