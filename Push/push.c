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

void pushIt(t_lst **a, t_lst **b, int len)
{
	int pivot;

	if (len > 3)
	{
		pivot = get_median(*a, len);
		if ((*a)->val < pivot)
		{
			if ((*a)->next->val <= pivot && (*a)->next->val < (*a)->val)
				swap(a, 'a', b);
			push(a, 'b', b);
		}
		else if ((*a)->next->val <= pivot)
			swap(a, 'a', b);
		else
			rotate(a, 'a', b);
		if (*b)
			if ((*b)->next)
				if ((*b)->val < (*b)->next->val)
					swap(b, 'b', a);
		pushIt(a, b, lstlen(*a));
	}
sorta(a, b);
printlst(*a, 'a');
printlst(*b, 'b');
}