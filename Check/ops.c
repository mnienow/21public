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
	t_lst	*new;
	t_lst	*tmp;

	if (!*lst || !(*lst)->next)
		write(1, "\n", 1);
	else
	{
		write(1, "s", 1);
		write(1, &ch, 1);
		tmp = (t_lst *)malloc(sizeof(t_lst));
		tmp->val = (*lst)->val;
		tmp->next = 0;
		new = (*lst);
		new = new->next;
		(*lst)->val = new->val;
		new->val = tmp->val;
		*lst = (*lst);
		write(1, "\n", 1);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}

void	push(t_lst **from, char ch, t_lst **to)
{
	t_lst	*tmp;

	tmp = 0;
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
			tmp = lstnew((*from)->val);
			tmp->next = *to;
			*to = tmp;
		}
		tmp = *from;
		*from = (*from)->next;
		lstdelone(&tmp);
		write(1, "\n", 1);
		ch == 'b' ? printlst(*from, 'a') : printlst(*to, ch);
		ch == 'b' ? printlst(*to, ch) : printlst(*from, 'b');
	}
}

void	rotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*last;
	t_lst	*tmp;

	tmp = *lst;
	last = 0;
	if (!*lst || !(*lst)->next)
		write(1, "\n", 1);
	else
	{
		write(1, "r", 1);
		write(1, &ch, 1);
		last = lstnew((*lst)->val);
		*lst = (*lst)->next;
		lstdelone(&tmp);
		tmp = (*lst);
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = last;
		(*lst) = tmp;
		write(1, "\n", 1);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}

void	rrotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*first;
	t_lst	*tmp;

	tmp = *lst;
	first = 0;
	if (!*lst || !(*lst)->next)
		write(1, "\n", 1);
	else
	{
		write(1, "rr", 2);
		write(1, &ch, 1);
		while ((*lst)->next->next)
			(*lst) = (*lst)->next;
		first = lstnew((*lst)->next->val);
		lstdelone(&(*lst)->next);
		(*lst)->next = 0;
		*lst = tmp;
		first->next = *lst;
		*lst = first;
		write(1, "\n", 1);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
	}
}
