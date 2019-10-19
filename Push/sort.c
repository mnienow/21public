/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/03 21:49:51 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a(t_lst **a, t_lst **b)
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
	else
	{
		if ((*a)->val > (*a)->next->next->val)
			rev_rotate(a, 'a', b);
	}
}
