/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/03 21:49:51 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	long	*longs;
	t_lst	*a;
	t_lst	*b;

	if (argc > 1)
	{
		longs = valider(&argv[0]);
		a = set_stack_a(longs);
		b = 0;
		pushIt(&a, &b, ft_arrlen((void**)&longs));
	}
	else
		write(1, "Error\n", 6);
	return (0);
}