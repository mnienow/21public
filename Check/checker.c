/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/25 19:57:08 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		finalcheck(t_lst *a, t_lst *b)
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
            write(1, "OK\n", 3);
	}
    write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
  size_t	len;
  char    **args;

	if (argc > 1)
	{
		len = argc - 1;
		if (argc == 2)
		{
		    args = ft_strsplit(argv[1], ' ');
		    len = ft_arrlen((void**)args);
            a = valider(args, len);
            free(args);
        }
		else
            a = valider(&argv[1], len);
		b = 0;
		parser(&a, &b);
		finalcheck(a, b);
	}
	else
		write(2, "Error\n", 6);
	return 0;
}
