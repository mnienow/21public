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

int		findmed(t_lst **a)
{
	t_lst	*sa;
	int		count;
	int		min;
	int		max;
	int		val;

	min = 0;
	max = 0;
	count = 0;
	sa = *a;
	while (sa)
	{
		sa->val < min ? min = sa->val : 0;
		sa->val > max ? max = sa->val : 0;
		sa = sa->next;
	}
	val = (max - min) / 2;
	sa = *a;
	while (sa)
	{
		if (sa->val < val)
			count++;
		sa = sa->next;
	}
	return (count);
}

t_lst	*lstcpy(t_lst *a)
{
	t_lst	*cp;
	t_lst	*cps;

	cp = (t_lst *)malloc(sizeof(t_lst));
	cp->val = a->val;
	cps = cp;
	while (a->next)
	{
		cp->next = lstnew(a->next->val);
		a = a->next;
		cp = cp->next;
	}
	return (cps);
}

int		findercycle(t_lst *sa, int len, int val, int count)
{
	int		tmp;
	t_lst	*s;

	while (sa && count)
	{
		s = sa;
		count = len - 1;
		while (s->next)
		{
			if (s->val > s->next->val)
			{
				tmp = s->next->val;
				s->next->val = s->val;
				s->val = tmp;
			}
			else
				count--;
			s = s->next;
		}
		val = s->val;
	}
	len = len / 2;
	while (--len)
		sa = sa->next;
	return (sa->val);
}

int		findmed2(t_lst **a, int len)
{
	t_lst	*sa;

	sa = lstcpy(*a);
	return (findercycle(sa, len, 0, 1));
}
