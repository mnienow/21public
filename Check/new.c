/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/05 17:16:34 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		findmed(t_lst **list)
{
	t_lst	*link;
	int		count;
	int		min;
	int		max;
	int		val;

	min = 0;
	max = 0;
	count = 0;
	link = *list;
	while (link)
	{
		link->val < min ? min = link->val : 0;
		link->val > max ? max = link->val : 0;
		link = link->next;
	}
	val = (max - min) / 2;
	link = *list;
	while (link)
	{
		if (link->val < val)
			count++;
		link = link->next;
	}
	return (count);
}

t_lst	*lstcpy(t_lst *list)
{
	t_lst	*copy;
	t_lst	*link;

	copy = (t_lst *)malloc(sizeof(t_lst));
	copy->val = list->val;
	link = copy;
	while (list->next)
	{
		copy->next = lstnew(list->next->val);
		list = list->next;
		copy = copy->next;
	}
	return (link);
}

int		findercycle(t_lst *list, int len, int count)
// int		findercycle(t_lst *sa, int len, int val, int count)
{
	int		tmp;
	t_lst	*link;

	while (list && count)
	{
		link = list;
		count = len - 1;
		while (link->next)
		{
			if (link->val > link->next->val)
			{
				tmp = link->next->val;
				link->next->val = link->val;
				link->val = tmp;
			}
			else
				count--;
			link = link->next;
		}
		// val = s->val;
	}
	len = len / 2 + (len % 2);
	while (--len)
		list = list->next;
	return (list->val);
}

int		findmed2(t_lst **list, int len)
{
	t_lst	*link;

	link = lstcpy(*list);
	return (findercycle(link, len, 1));
	// return (findercycle(link, len, 0, 1));
}

/*int	get_median(t_stack *a)
{
	t_pslst	*tmp;
	int		arr[a->ac + 1];
	int		i;
	int		j[2];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i++] = tmp->n;
		tmp = tmp->nxt;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[a->ac] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->ac];
			}
	}
	return (arr[i / 2]);
}*/