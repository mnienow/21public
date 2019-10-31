/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/27 14:47:11 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     sorted(t_lst *lst)
{
    while (lst->next)
    {
        if (lst->index > lst->next->index)
            return 0;
        lst = lst->next;
    }
    return 1;
}

int		main(int argc, char **argv)
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
            len = ft_arrlen((void **)args);
            a = valider(args, len);
            free(args);
        }
	    else
            a = valider(&argv[1], len);
	    if (sorted(a))
            return 0;
		b = 0;
		push_swap(&a, &b, len);
		sort(&a, &b);
	}
	else
		write(2, "Error\n", 6);
	return 0;
}