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

void        pushS(t_lst **a, t_lst **b, int len)
{
    if (*b) {
        while (len) {
            if ((*b)->val > (*b)->next->val) {
                if ((*b)->next->val > (*b)->next->next->val) {
                    push(b, 'b', a);
                    len--;
                }
                else
                    rotate(b, 'b', a);
            }
            else
                swap(b, 'b', a);
        }
    }
}

void	sortS(t_lst **a, t_lst **b, int len)
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
	pushS(a, b, len);
}

void	sortb(t_lst **a, t_lst **b)
{
//    while (!sorted(*b)) {
        if ((*b)->val < (*b)->next->val) {
            if ((*b)->val > (*b)->next->next->val)
                swap(b, 'b', a);
            else
                rotate(b, 'b', a);
            if ((*b)->val < (*b)->next->val)
                swap(b, 'b', a);
        } else {
            if ((*b)->val > (*b)->next->next->val)
                rev_rotate(b, 'b', a);
        }
//    }
}