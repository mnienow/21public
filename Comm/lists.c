/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:27:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/26 18:37:25 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*lstnew(int val, int index)
{
	t_lst	*list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	list->val = val;
	list->next = NULL;
	list->prev = list;
	list->index = index;
	return (list);
}

void	printlst(t_lst *begin, char lst)
{
	char	*str;
	t_lst	*start;

	str = 0;
	start = begin;
	if (begin)
	{
		write(1, "stack ", 6);
		write(1, &lst, 1);
		write(1, "\n", 1);
		while (start)
		{
			str = ft_itoa(start->val);
//			write(1, str, ft_strlen(str));
//			write(1, "\n", 1);
printf("%s - %d\n", str, start->index);
			start = start->next;
			free(str);
			str = 0;
		}
	}
}

void	lstdelone(t_lst **alst)
{
	if (*alst != NULL)
		ft_memdel((void *)alst);
	*alst = 0;
}
