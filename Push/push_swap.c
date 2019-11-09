/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/28 21:49:42 by mnienow          ###   ########.fr       */
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

	if (argc > 1)
	{
        len = argc - 1;
        a = valider(&argv[1], &len);
	    if (sorted(a))
            return 0;
		b = 0;
		push_swap(&a, &b, len, 0);
		sort(&a, &b);
	}
	else
		err(0);
	return 0;
}