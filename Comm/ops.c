/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:35:54 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 14:38:38 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		swap_lists(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = lstnew(((*a)->val), (*a)->index);
	(*a)->val = (*b)->val;
	(*a)->index = (*b)->index;
	(*b)->val = tmp->val;
	(*b)->index = tmp->index;
	free(tmp);
}

void		swap(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*linka;
	t_lst	*linkb;

	(void)sec;
	linka = *lst;
	if (!linka || !linka->next)
		write(1, "\n", 1);
	else
	{
		write(1, "s", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
		linkb = linka->next;
		swap_lists(&linka, &linkb);
	}
}

void		push(t_lst **from, char ch, t_lst **to)
{
	t_lst	*link;

	if (*from)
	{
		write(1, "p", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
		if (!*to)
			*to = lstnew((*from)->val, (*from)->index);
		else
		{
			link = lstnew((*from)->val, (*from)->index);
			link->next = *to;
			link->prev = (*to)->prev;
			(*to)->prev = link;
			*to = link;
		}
		link = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = link->prev;
		lstdelone(&link);
	}
}

void		rotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*link;
	t_lst	*last;

	(void)sec;
	link = (*lst);
	if (!link || !link->next)
		write(1, "\n", 1);
	else
	{
		write(1, "r", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
		last = lstnew(link->val, link->index);
		link->prev->next = last;
		last->prev = link->prev;
		*lst = (*lst)->next;
		lstdelone(&link);
		(*lst)->prev = last;
	}
}

void		rev_rotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*first;
	t_lst	*link;

	(void)sec;
	link = *lst;
	if (!link || !link->next)
		write(1, "\n", 1);
	else
	{
		write(1, "rr", 2);
		write(1, &ch, 1);
		write(1, "\n", 1);
		link = link->prev->prev;
		first = lstnew(link->next->val, link->next->index);
		first->next = *lst;
		first->prev = link;
		(*lst)->prev = first;
		lstdelone(&link->next);
		*lst = first;
	}
}
