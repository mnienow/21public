/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 14:45:32 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			multi_pivot(t_lst *list, int median)
{
	t_lst	*link;
	int		pivot;
	int		min;
	int		max;

	min = 2147483647;
	max = 0;
	pivot = 0;
	link = list;
	while (link)
	{
		if (link->index > max)
			max = link->index;
		if (link->index < min)
			min = link->index;
		if (link->val == median)
			pivot = link->index;
		link = link->next;
	}
	return (get_value(list, min + (pivot - min) / 2));
}

void		push_b(t_lst **a, t_lst **b, int len, int pivot)
{
	int		mpivot;

	mpivot = multi_pivot(*a, pivot);
	while (len)
	{
		if ((*a)->val < pivot)
		{
			if ((*a)->next->val < pivot && (*a)->next->val < (*a)->val)
				swap(a, 'a', b);
			push(a, 'b', b);
			if ((*b)->next)
				if ((*b)->val < mpivot)
					rotate(b, 'b', a);
			len--;
		}
		else if ((*a)->next->val < pivot)
			swap(a, 'a', b);
		else
			rev_rotate(a, 'a', b);
	}
}

void		re_push(t_lst **a, t_lst **b, int len, int pivot)
{
	int		i;
	int		mpivot;

	i = -1;
	while (*b && ++i < len)
		push(b, 'a', a);
	mpivot = multi_pivot(*a, pivot);
	push_b(a, b, len / 2, mpivot);
	len = len - (int)lstlen(*b);
	push_b(a, b, len, pivot);
}

void		push_swap(t_lst **a, t_lst **b, int len, int i)
{
	int		pivot;

	if (len > 3)
	{
		pivot = get_median(*a, len);
		if (len == 4)
			push_b(a, b, 1, pivot);
		else if (len > 124)
		{
			push_b(a, b, len / 2, pivot);
			if (i++ == 0)
				re_push(a, b, len / 2, pivot);
		}
		else
			push_b(a, b, len / 2, pivot);
		push_swap(a, b, lstlen(*a), i);
	}
	else
		sort_a(a, b);
}
