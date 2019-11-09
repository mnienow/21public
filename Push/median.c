/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/11/09 13:17:38 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t		lstlen(t_lst *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

int			get_value(t_lst *list, int index)
{
	t_lst	*link;

	link = list;
	while (link)
	{
		if (link->index == index)
			return (link->val);
		link = link->next;
	}
	err(2);
	return (0);
}

int			get_median(t_lst *list, size_t len)
{
	size_t	i;
	int		min;
	int		max;
	t_lst	*link;

	i = -1;
	min = 2147483647;
	max = 0;
	link = list;
	while (link && ++i < len)
	{
		if (min > link->index)
			min = link->index;
		if (max < link->index)
			max = link->index;
		link = link->next;
	}
	if (len == 4)
		return (get_value(list, min + 1));
	return (get_value(list, max - (max - min) / 2));
}
