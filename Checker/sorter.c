/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:41:21 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 18:41:23 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_lst *lst)
{
	t_lst	*new;
	t_lst	*tmp;

	printf("swap started\n");
	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->val = lst->val;
	tmp->next = 0;
	new = lst;
	while (new->next)
		new = new->next;
	lst->val = new->val;
	new->val = tmp->val;
	printlst(lst);
	printf("swap completed\n");
}
