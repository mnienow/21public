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

void	pushIt(t_lst **a, t_lst **b, int len)
{
	t_lst	**sa;
	t_lst	**sb;
	int		pivot;
	int		l;

	l = len;
	sa = a;
	sb = b;
	while (len > 3)
	{
		while (l >= len / 2 && len > 3)
		{
			pivot = findmed2(a, len);
			printf("pivot = %d\n", pivot);
			if ((*a)->val < pivot)
			{
				if ((*a)->next->val <= pivot && (*a)->next->val < (*a)->val)
					swap(a, 'a', b);
				push(sa, 'b', sb);
				len--;
			}
			else if ((*a)->next->val <= pivot)
				swap(a, 'a', b);
			else
				rotate(sa, 'a', sb);
			if (*b)
				if ((*b)->next)
					if ((*b)->val < (*b)->next->val)
						swap(b, 'b', a);
			printf("Len = %d\n", len);
		}
		// sortb(b, a);
		parser2(a, b, len);
		break ;
	}
	sorta(a, b);
	printlst(*a, 'a');
	printlst(*b, 'b');
}