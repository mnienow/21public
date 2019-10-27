/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/27 22:44:43 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_b(t_lst **a, t_lst **b, int len, int pivot)
{
    while (len)
    {
        if ((*a)->val < pivot)
        {
            if ((*a)->next->val < pivot && (*a)->next->val < (*a)->val)
                swap(a, 'a', b);
            push(a, 'b', b);
            len--;
        }
        else if ((*a)->next->val < pivot)
            swap(a, 'a', b);
        else
            rev_rotate(a, 'a', b);
    }
}

void        push_swap(t_lst **a, t_lst **b, int len)
{
	int     pivot;

	if (len > 3)
	{
		pivot = get_median(a, len);
		if (len == 4)
		    push_b(a, b, 1, pivot);
		else
            push_b(a, b, len / 2, pivot);
		push_swap(a, b, lstlen(*a));
	}
	else
        sort_a(a, b);
}

