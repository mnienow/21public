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

#include "checker.h"

void	swap(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*new;
	t_lst	*tmp;

	if (!*lst || !(*lst)->next)
		write(1, "nothing to swap\n", 17);
	else
	{
		write(1, "swap started\n", 14);
		tmp = (t_lst *)malloc(sizeof(t_lst));
		tmp->val = (*lst)->val;
		tmp->next = 0;
		new = (*lst);
		new = new->next;
		(*lst)->val = new->val;
		new->val = tmp->val;
		*lst = (*lst);
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
		write(1, "swap completed\n", 16);
	}
}

void	push(t_lst **from, char ch, t_lst **to)
{
	t_lst	*tmp;

	tmp = 0;
	if (!*from)
		write(1, "nothing to push\n", 17);
	else
	{
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
		ch == 'a' ? printlst(*from, ch) : printlst(*to, 'a');
		ch == 'a' ? printlst(*to, 'b') : printlst(*from, ch);
	}
}

void	rotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*last;
	t_lst	*tmp;

	tmp = *lst;
	last = 0;
	if (!*lst || !(*lst)->next)
		write(1, "nothing to rotate\n", 19);
	else
	{
		write(1, "rotate started\n", 16);
		last = lstnew((*lst)->val);
		*lst = (*lst)->next;
		lstdelone(&tmp);
		tmp = (*lst);
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = last;
		(*lst) = tmp;
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
		write(1, "rotate completed\n", 18);
	}
}

void	rrotate(t_lst **lst, char ch, t_lst **sec)
{
	t_lst	*first;
	t_lst	*tmp;

	tmp = *lst;
	first = 0;
	if (!*lst || !(*lst)->next)
		write(1, "nothing to rrotate\n", 19);
	else
	{
		write(1, "rrotate started\n", 16);
		while ((*lst)->next->next)
			(*lst) = (*lst)->next;
		first = lstnew((*lst)->next->val);
		lstdelone(&(*lst)->next);
		(*lst)->next = 0;
		*lst = tmp;
		first->next = *lst;
		*lst = first;
		ch == 'a' ? printlst(*lst, ch) : printlst(*sec, 'a');
		ch == 'a' ? printlst(*sec, 'b') : printlst(*lst, ch);
		write(1, "rrotate completed\n", 18);
	}
}
