/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 13:47:15 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swapper(t_lst **a, t_lst **b, char *line)
{
	if (!ft_strcmp(line, "sb"))
		swap(b, 'b', a);
	else if (!ft_strcmp(line, "sa"))
		swap(a, 'a', b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(a, 'a', b);
		swap(b, 'b', a);
	}
	else
		err(0);
}

void	rot(t_lst **a, t_lst **b, char *line)
{
	if (line[1] == 'a')
		rotate(a, 'a', b);
	else if (line[1] == 'b')
		rotate(b, 'b', a);
	else if (line[1] == 'r')
	{
		rotate(a, 'a', b);
		rotate(b, 'b', a);
	}
	else
		err(0);
}

void	rrot(t_lst **a, t_lst **b, char *line)
{
	if (line[1] == 'r')
	{
		if (line[2] == 'a')
			rev_rotate(a, 'a', b);
		else if (line[2] == 'b')
			rev_rotate(b, 'b', a);
		else if (line[2] == 'r')
		{
			rev_rotate(a, 'a', b);
			rev_rotate(b, 'b', a);
		}
		else
			err(0);
	}
	else
		err(0);
}

void	parser(t_lst **a, t_lst **b)
{
	char *line;

	line = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == 's')
			swapper(a, b, line);
		else if (!ft_strcmp(line, "pa"))
			push(b, 'a', a);
		else if (!ft_strcmp(line, "pb"))
			push(a, 'b', b);
		else if (line[0] == 'r')
		{
			if (ft_strlen(line) == 2)
				rot(a, b, line);
			else if (ft_strlen(line) == 3)
				rrot(a, b, line);
			else
				err(0);
		}
		else
			err(0);
	}
	free(line);
}
