/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/27 14:47:11 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	size_t	len;

	if (argc > 1)
	{
		len = argc - 1;
		a = valider(&argv[1], len);
//		printf("%s\n", argv[1]);
		b = 0;
		push_swap(&a, &b, len);
		insertion_sort(&a, &b);
//		printlst(a, 'a');
//		printlst(b, 'b');
	}
	else
		write(1, "Error\n", 6);
	return (0);
}