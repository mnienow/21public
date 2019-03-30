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

int		parser(t_lst *a, t_lst *b)
{
	char	*line;
	int		i;
	
	line = 0;
	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
		{
			printf("sa confirmed\n");
			swap(a);
		}
		if (ft_strcmp(line, "sb") == 0)
			swap(b);
	}
	return (0);
}

int		checker(char **str, int size)
{
	int		i;
	t_lst	*a;
	t_lst	*begin;
	t_lst	*b;

	i = 0;
	a = (t_lst *)malloc(sizeof(t_lst));
	b = (t_lst *)malloc(sizeof(t_lst));
	a->val = ft_atoi(str[--size]);
	begin = a;
	while (--size > -1)
	{
		a->next = lstnew(ft_atoi(str[size]));
		a = a->next;
	}
	printlst(begin);
	parser(a, b);
	// printlst(begin);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (checker(&argv[1], argc - 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}