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

void	sorta(t_lst **a, t_lst **b, int len)
{
	(void)len;
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
			rrotate(a, 'a', b);
	}
}

void	parser2(t_lst **a, t_lst **b, int len)
{
	t_lst	**sa;
	t_lst	**sb;
	int		pivot;
	int		l;

	l = len;
	sa = a;
	sb = b;
	while (len > 3)
	{
		while (l >= len / 2 && len > 3)
		{
			pivot = findmed2(a, len);
			printf("pivot = %d\n", pivot);
			if ((*a)->val < pivot)
			{
				if ((*a)->next->val <= pivot && (*a)->next->val < (*a)->val)
					swap(a, 'a', b);
				push(sa, 'b', sb);
				len--;
			}
			else if ((*a)->next->val <= pivot)
				swap(a, 'a', b);
			else
				rotate(sa, 'a', sb);
			if (*b)
				if ((*b)->next)
					if ((*b)->val < (*b)->next->val)
						swap(b, 'b', a);
			printf("Len = %d\n", len);
		}
		// sortb(b, a, len);
		parser2(a, b, len);
		break ;
	}
	sorta(a, b, len);
	printlst(*a, 'a');
	printlst(*b, 'b');
}
