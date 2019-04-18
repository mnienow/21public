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

static void	parser1(t_lst **a, t_lst **b)
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
		else
			err();
	}
}

void		firstcheck(t_lst *a)
{
	t_lst	*b;
	int		val;

	b = a;
	if (a->val > 2147483647 || a->val < -2147483648)
		err();
	while (a && a->next)
	{
		if (a->next->val > 2147483647 || a->next->val < -2147483648)
			err();
		val = a->val;
		while (a->next)
		{
			if (a->next->val != val)
				a = a->next;
			else
				err();
		}
		b = b->next;
		a = b;
	}
}

int			checker(char **str, int i, char op)
{
	t_lst	*a;
	t_lst	*b;

	a = (t_lst *)malloc(sizeof(t_lst));
	a->val = ft_atol(str[i++]);
	b = a;
	while (str[i])
	{
		a->next = lstnew(ft_atol(str[i++]));
		a = a->next;
	}
	a->next = 0;
	a = b;
	b = 0;
	firstcheck(a);
	if (!op)
	{
		parser1(&a, &b);
		if (finalcheck(a, b))
			return (-2);
	}
	else
		parser2(&a, &b, i);
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
