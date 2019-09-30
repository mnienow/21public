/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:41:21 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 18:41:23 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*link;
	int		tmp;

	link = *lst;
	tmp = 0;
	if (!link || !link->next)
		write(1, "\n", 1);
	else
	{
		tmp = (*lst)->val;
		write(1, "s", 1);
		write(1, &ch, 1);
		link = link->next;
		(*lst)->val = link->val;
		link->val = tmp;
		write(1, "\n", 1);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}

void	push(t_lst **from, char ch, t_lst **to)
{
	t_lst	*link;

	link = 0;
	if (!*from)
		write(1, "\n", 1);
	else
	{
		write(1, "p", 1);
		write(1, &ch, 1);
		if (!*to)
			*to = lstnew((*from)->val);
		else
		{
			link = lstnew((*from)->val);
			link->next = *to;
			*to = link;
		}
		link = *from;
		*from = (*from)->next;
		lstdelone(&link);
		write(1, "\n", 1);
		ch == 'b' ? printlst(*from, 'a') : printlst(*to, ch);
		ch == 'b' ? printlst(*to, ch) : printlst(*from, 'b');
	}
}

void		rotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*link;
	t_lst	*last;

    link = (*lst);
	if (!link || !link->next)
		write(1, "\n", 1);
	else
	{
		write(1, "r", 1);
		write(1, &ch, 1);
		last = lstnew(link->val);
        link->prev->next = last;
        last->prev = link->prev;
        *lst = (*lst)->next;
		lstdelone(&link);
        (*lst)->prev = last;
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}

void	rrotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*first;
	t_lst	*link;

	link = *lst;
	if (!link || !link->next)
		write(1, "\n", 1);
	else
	{
		write(1, "rr", 2);
		write(1, &ch, 1);
		link = link->prev->prev;
		first = lstnew(link->next->val);
		lstdelone(&link->next);
		first->next = *lst;
		first->prev = link;
		*lst = first;
		write(1, "\n", 1);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}

t_lst	*set_stack_a(long *longs, size_t len)
{
	t_lst	*a;
	t_lst   *link;

	a = lstnew((int)longs[--len]);
	link = a;
	while (len)
	{
		a->prev = lstnew((int)longs[--len]);
		a->prev->next = a;
		a = a->prev;
	}
	a->prev = link;
	return (a);
}