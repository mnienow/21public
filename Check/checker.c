/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 15:48:58 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			finalcheck(t_lst *a, t_lst *b)
{
	if (!b && a)
	{
		while (a->next)
		{
			if (a->val < a->next->val)
				a = a->next;
			else
				break ;
		}
		if (!a->next)
			return (0);
	}
	return (-1);
}

static void	parser(t_lst **a, t_lst **b)
{
	char	*line;

	line = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
			swap(a, 'a', b);
		else if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swap(b, 'b', a);
		else if (!ft_strcmp(line, "pa"))
			push(b, 'a', a);
		else if (!ft_strcmp(line, "pb"))
			push(a, 'b', b);
		else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
			rotate(a, 'a', b);
		else if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
			rotate(b, 'b', a);
		else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
			rrotate(a, 'a', b);
		else if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
			rrotate(b, 'b', a);
		// else
			// err();
	}
}

int			checker(long *longs, int i, char push)
{
	t_lst	*a;
	t_lst	*b;

	a = (t_lst *)malloc(sizeof(t_lst));
	a->val = (int)longs[i++];
	b = a;
	while (longs[i])
	{
		a->next = lstnew((int)longs[i++]);
		a = a->next;
	}
	a->next = 0;
	a = b;
	b = 0;
	if (!push)
	{
		parser(&a, &b);
		if (finalcheck(a, b))
			return (-2);
	}
	else
		pushIt(&a, &b, i);
	return (0);
}