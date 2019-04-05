/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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

static int	parser1(t_lst **a, t_lst **b)
{
	char	*line;

	line = 0;
	printlst(*a, 'a');
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
			swap(a, 'a', b);
		if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swap(b, 'b', a);
		if (!ft_strcmp(line, "pa"))
			push(b, 'b', a);
		if (!ft_strcmp(line, "pb"))
			push(a, 'a', b);
		if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
			rotate(a, 'a', b);
		if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
			rotate(b, 'b', a);
		if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
			rrotate(a, 'a', b);
		if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
			rrotate(b, 'b', a);
	}
	printlst(*a, 'a');
	return (0);
}

int			firstcheck(t_lst *a)
{
	t_lst	*b;
	int		val;

	val = 0;
	b = a;
	if (a)
	{
		while (a->next)
		{
			val = a->val;
			while (a->next)
			{
				if (a->next->val != val)
					a = a->next;
				else
					return (-1);
			}
			b = b->next;
			a = b;
		}
	}
	return (0);
}

int			checker(char **str, char op)
{
	int		i;
	t_lst	*a;
	t_lst	*b;

	i = 0;
	a = (t_lst *)malloc(sizeof(t_lst));
	a->val = ft_atoi(str[i++]);
	b = a;
	while (str[i])
	{
		a->next = lstnew(ft_atoi(str[i++]));
		a = a->next;
	}
	a = b;
	b = 0;
	if (firstcheck(a))
		err();
	if (!op)
	{
		parser1(&a, &b);
		if (finalcheck(a, b))
			return (-2);
	}
	else
		parser2(&a, &b);
	return (0);
}

void		valider1(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= 48 && str[i][j] <= 57) || str[i][j] == 45 ||
			str[i][j] == 32)
				j++;
			else
				err();
		}
	}
}
