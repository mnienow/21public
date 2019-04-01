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

#include "checker.h"
#include "../libft/libft.h"

int		finalcheck(t_lst *a, t_lst *b)
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

int		parser(t_lst **a, t_lst **b)
{
	char	*line;

	line = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
			swap(a, 'a');
		if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swap(b, 'b');
		if (!ft_strcmp(line, "pa"))
			push(b, 'b', a);
		if (!ft_strcmp(line, "pb"))
			push(a, 'a', b);
		if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
			rotate(a, 'a');
		if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
			rotate(b, 'b');
		if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
			rrotate(a, 'a');
		if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
			rrotate(b, 'b');
	}
	return (0);
}

int		checker(char **str)
{
	int		i;
	t_lst	*a;
	t_lst	*sa;
	t_lst	*b;

	i = 0;
	a = (t_lst *)malloc(sizeof(t_lst));
	b = 0;
	a->val = ft_atoi(str[i++]);
	sa = a;
	while (str[i])
	{
		a->next = lstnew(ft_atoi(str[i++]));
		a = a->next;
	}
	printlst(sa, 'a');
	parser(&sa, &b);
	printlst(sa, 'a');
	if (finalcheck(sa, b))
		return (-2);
	return (0);
}

int		main(int argc, char **argv)
{
	int result;

	result = 0;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	result = checker(&argv[1]);
	if (result == -1)
		write(1, "Error\n", 6);
	else if (result == -2)
		write(1, "KO\n", 4);
	else if (result == 0)
		write(1, "OK\n", 4);		
	return (0);
}

/* первый аргумент после сортировки должен стать минимальным, а последний - максимальным.*/