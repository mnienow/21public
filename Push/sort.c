/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:40:39 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 13:42:33 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		sort_a(t_lst **a, t_lst **b)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		if ((*a)->val > (*a)->next->val)
		{
			if ((*a)->val < (*a)->prev->val)
				swap(a, 'a', b);
			else
				rotate(a, 'a', b);
		}
		else if (!((*a)->val < (*a)->next->val &&
					(*a)->next->val < (*a)->prev->val))
			rev_rotate(a, 'a', b);
	}
}

int			position(int index, t_lst **b)
{
	size_t	len;
	t_lst	*link;

	len = lstlen(*b) / 2;
	link = *b;
	while (len)
	{
		if (link->index + 1 == index)
			return (1);
		link = link->next;
		len--;
	}
	return (0);
}

void		sort(t_lst **a, t_lst **b)
{
	while (*b)
	{
		if ((*a)->index == (*b)->index + 1)
			push(b, 'a', a);
		else if ((*b)->next->index + 1 == (*a)->index)
			swap(b, 'b', a);
		else if (position((*a)->index, b))
			rotate(b, 'b', a);
		else
			rev_rotate(b, 'b', a);
	}
}
