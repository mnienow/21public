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

void        pushA(t_lst **a, t_lst **b, int len) {
        while(*b)
            push(b, 'a', a);
}

void        pushB(t_lst **a, t_lst **b, int len)
{
	int     pivot;
	int     h_len;

	h_len = len / 2;
	if (len > 3 || !sortedA(*a))
	{
		pivot = get_median(*a, len);
		while (h_len)
		{
			if ((*a)->val < pivot)
			{
				if ((*a)->next->val < pivot && (*a)->next->val < (*a)->val)
					swap(a, 'a', b);
				push(a, 'b', b);
				h_len--;
			}
			else if ((*a)->next->val < pivot)
				swap(a, 'a', b);
			else
                rev_rotate(a, 'a', b);
			if (sortedA(*a)) {
                break;
            }
        }
		pushB(a, b, lstlen(*a));
	}
	else
        sortS(a, b, len);
	pushA(a, b, len);
}