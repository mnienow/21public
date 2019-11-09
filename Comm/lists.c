/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:43:59 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 14:46:31 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst		*lstnew(int val, int index)
{
	t_lst	*list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	list->val = val;
	list->next = NULL;
	list->prev = list;
	list->index = index;
	return (list);
}

void		printlst(t_lst *begin, char lst)
{
	char	*str;
	t_lst	*start;

	start = begin;
	if (begin)
	{
		write(1, "stack ", 6);
		write(1, &lst, 1);
		write(1, "\n", 1);
		while (start)
		{
			str = ft_itoa(start->val);
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			start = start->next;
			free(str);
		}
	}
}

void		lstdelone(t_lst **alst)
{
	if (*alst != NULL)
		ft_memdel((void *)alst);
	*alst = 0;
}

void		set_indexes(t_lst **list, const long *longs, size_t len)
{
	size_t	i;
	t_lst	*link;

	i = 0;
	link = *list;
	while (i < len)
	{
		if ((*list)->val == longs[i])
			(*list)->index = ++i;
		*list = (*list)->prev;
	}
	*list = link;
}

t_lst		*set_stack_a(long *longs, size_t len)
{
	int		last;
	t_lst	*a;
	t_lst	*link;

	last = (int)len - 1;
	a = lstnew((int)longs[--len], 0);
	link = a;
	while (len)
	{
		a->prev = lstnew((int)longs[--len], 0);
		a->prev->next = a;
		a = a->prev;
	}
	a->prev = link;
	ft_qs(longs, 0, last++);
	set_indexes(&a, longs, last);
	return (a);
}
