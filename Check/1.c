/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/05 17:16:34 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		findmed(t_lst **a, int i)
{
	t_lst	*sa;
	int		count;

	count = i / 2;
	printf("%d\n", count);
	sa = *a;
	while (count && sa)
	{
		if (sa->val < sa->next->val)
			count--;
		sa = sa->next;
	}
	printf("%d\n", count);
	return (sa->val);
}

/* найти правильный алгоритм нахождения медианы - это не сложно :) */
