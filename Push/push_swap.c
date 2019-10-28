/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/28 21:49:42 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int 	sorted(t_lst **a)
{
	t_lst *link;

	link = *a;
	while (link->next)
	{
		if (link->val > link->next->val)
			break;
		link = link->next;
	}
	link = link->next;
	if (link == NULL)
		return 1;
	return 0;
}

int		main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	size_t	len;
	char 	**args;

	if (argc > 1)
	{
		if (argc == 2)
			args = ft_strsplit(argv[1], ' ');
		else
			args = &argv[1];
		len = ft_arrlen((void**)args);
		a = valider(args, len);
		if (sorted(&a))
		{
			exit(0);
		}
		b = 0;
		push_swap(&a, &b, len);
		insertion_sort(&a, &b);
//		printlst(a, 'a');
//		printlst(b, 'b');
	}
	else
		write(2, "Error\n", 6);
	return (0);
}