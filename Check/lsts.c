/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:27:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 18:27:33 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*lstnew(long val)
{
	t_lst	*arr;

	if (!(arr = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	arr->val = val;
	arr->next = NULL;
	return (arr);
}

void	printlst(t_lst *begin, char lst)
{
	t_lst	*start;
	char	*val;

	val = 0;
	start = begin;
	if (begin)
	{
		write(1, "stack ", 6);
		write(1, &lst, 1);
		write(1, "\n", 1);
		while (start)
		{
			val = ft_itoa(start->val);
			write(1, val, ft_strlen(val));
			write(1, "\n", 1);
			start = start->next;
			free(val);
			val = 0;
		}
	}
}

void	lstdelone(t_lst **alst)
{
	if (*alst != NULL)
		ft_memdel((void **)alst);
}

void	err(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	parser2(t_lst **a, t_lst **b, int len)
{
	t_lst	**sa;
	t_lst	**sb;
	int		pivot;
	int		r;
	int		l;

	r = 0;
	sa = a;
	sb = b;
	l = len;
	while ((l = (l / 2) + (l % 2)) >= 3)
	{
		pivot = findmed2(a, len);
		printf("pivot = %d\n", pivot);
		l == 3  && len % 2 ? l-- : 0;
		len = l;
		while (l)
		{
			if ((*a)->val <= pivot)
			{
				if ((*a)->next->val <= pivot && (*a)->next->val < (*a)->val)
					swap(a, 'a', b);
				push(sa, 'b', sb);
				l--;
			}
			else if ((*a)->next->val <= pivot)
				swap(a, 'a', b);
			else
				rotate(sa, 'a', sb);
		}
		l = len;
		if (*b)
			if ((*b)->next)
				if ((*b)->val < (*b)->next->val)
					swap(b, 'b', a);
	}
}
