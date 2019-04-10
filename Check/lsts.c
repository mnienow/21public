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

t_lst	*lstnew(int val)
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

	sa = a;
	sb = b;
	pivot = findmed2(a, len);
	len /= 2;
	while (*a && len)
	{
		if ((*a)->val <= pivot)
		{
			push(sa, 'b', sb);
			len--;
		}
		else
			rotate(sa, 'a', sb);
	}
	// len = i / 2;
	// while (*b && len)
	// {
	// 	if ((*b)->val >= pivot)
	// 	{
	// 		push(sb, 'a', sa);
	// 		len--;
	// 	}
	// 	else
	// 		rotate(sa, 'b', sb);
	// }
}
