/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/27 13:45:57 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a(t_lst **a, t_lst **b)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if ((*a)->val > (*a)->next->val)
		{
			if ((*a)->val < (*a)->next->next->val)
				swap(a, 'a', b);
			else
				rotate(a, 'a', b);
			if ((*a)->val > (*a)->next->val)
				swap(a, 'a', b);
		}
		else if ((*a)->val > (*a)->next->next->val)
			rev_rotate(a, 'a', b);
		else
			swap(a, 'a', b);
		i++;
	}
}

void    insertion_sort(t_lst **a, t_lst **b) {
	while (*b)
	{
	    if ((*a)->index == (*b)->index + 1)
	        push(b, 'a', a);
	    else if ((*b)->next->index + 1 == (*a)->index)
	        swap(b, 'b', a);
	    else
	        rotate(b, 'b', a);
	}
}